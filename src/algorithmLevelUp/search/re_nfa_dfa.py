import re
from collections import deque
import json

# Conversion of regular expressions to non-deterministic finite automaton
# non-deterministic finite automaton to Deterministic Finite Automaton


def tokenize(regex):
    token_specification = [
        ("LPAREN", r"\("),
        ("RPAREN", r"\)"),
        ("STAR", r"\*"),
        ("UNION", r"\|"),
        ("CONCAT", r"\."),
        ("CHAR", r"[a-zA-Z0-9]"),
    ]
    tok_regex = "|".join(f"(?P<{pair[0]}>{pair[1]})" for pair in token_specification)
    get_token = re.compile(tok_regex).match
    pos = 0
    tokens = []
    while pos < len(regex):
        match = get_token(regex, pos)
        if not match:
            raise SyntaxError(f"Unexpected character: {regex[pos]}")
        pos = match.end()
        token_type = match.lastgroup
        token_value = match.group(0) if token_type == "CHAR" else None
        if token_type == "CONCAT":
            if tokens and tokens[-1][0] in {"CHAR", "RPAREN", "STAR"}:
                tokens.append(("CONCAT", None))
        else:
            tokens.append((token_type, token_value))
    return tokens


class RegexAST:
    def __init__(self, kind, left=None, right=None):
        self.kind = kind
        self.left = left
        self.right = right


def parse(tokens):
    def parse_concat():
        node = parse_star()
        while tokens and tokens[0][0] in {"CHAR", "LPAREN"}:
            node = RegexAST("CONCAT", node, parse_star())
        return node

    def parse_star():
        node = parse_union()
        while tokens and tokens[0][0] == "STAR":
            tokens.pop(0)
            node = RegexAST("STAR", node)
        return node

    def parse_union():
        node = parse_atom()
        while tokens and tokens[0][0] == "UNION":
            tokens.pop(0)
            node = RegexAST("UNION", node, parse_atom())
        return node

    def parse_atom():
        token = tokens.pop(0)
        if token[0] == "CHAR":
            return RegexAST("CHAR", token[1])
        elif token[0] == "LPAREN":
            node = parse_concat()
            if not tokens or tokens.pop(0)[0] != "RPAREN":
                raise SyntaxError("Missing RPAREN")
            return node
        else:
            raise SyntaxError("Unexpected token")

    return parse_concat()


def create_basic_nfa(symbol, start_index):
    nfa = {str(start_index): {symbol: [str(start_index + 1)]}, str(start_index + 1): {}}
    return nfa, start_index, start_index + 1, start_index + 2


def concatenate_nfa(nfa1, start1, accept1, nfa2, start2, accept2):
    if "" in nfa1[str(accept1)]:
        nfa1[str(accept1)][""].append(str(start2))
    else:
        nfa1[str(accept1)][""] = [str(start2)]
    nfa1.update(nfa2)
    return nfa1, start1, accept2


def union_nfa(nfa1, start1, accept1, nfa2, start2, accept2, start_index):
    start_state = str(start_index)
    accept_state = str(start_index + 1)
    nfa = {
        start_state: {"": [str(start1), str(start2)]},
        accept_state: {},
    }
    if "" in nfa1[str(accept1)]:
        nfa1[str(accept1)][""].append(accept_state)
    else:
        nfa1[str(accept1)][""] = [accept_state]
    if "" in nfa2[str(accept2)]:
        nfa2[str(accept2)][""].append(accept_state)
    else:
        nfa2[str(accept2)][""] = [accept_state]
    nfa.update(nfa1)
    nfa.update(nfa2)
    return nfa, start_state, accept_state, start_index + 2


def star_nfa(nfa, start, accept, start_index):
    start_state = str(start_index)
    accept_state = str(start_index + 1)
    nfa_star = {
        start_state: {"": [str(start), accept_state]},
        accept_state: {},
    }
    if "" in nfa[str(accept)]:
        nfa[str(accept)][""].extend([str(start), accept_state])
    else:
        nfa[str(accept)][""] = [str(start), accept_state]
    nfa_star.update(nfa)
    return nfa_star, start_state, accept_state, start_index + 2


def ast_to_nfa(ast, start_index=0):
    if ast.kind == "CHAR":
        nfa, start, accept, _ = create_basic_nfa(ast.left, start_index)
        return nfa, start, accept, start_index + 2
    elif ast.kind == "CONCAT":
        nfa1, start1, accept1, next_index = ast_to_nfa(ast.left, start_index)
        nfa2, start2, accept2, next_index = ast_to_nfa(ast.right, next_index)
        nfa, start, accept = concatenate_nfa(
            nfa1, start1, accept1, nfa2, start2, accept2
        )
        return nfa, start, accept, next_index
    elif ast.kind == "UNION":
        nfa1, start1, accept1, next_index = ast_to_nfa(ast.left, start_index)
        nfa2, start2, accept2, next_index = ast_to_nfa(ast.right, next_index)
        nfa, start, accept, next_index = union_nfa(
            nfa1, start1, accept1, nfa2, start2, accept2, next_index
        )
        return nfa, start, accept, next_index
    elif ast.kind == "STAR":
        nfa, start, accept, next_index = ast_to_nfa(ast.left, start_index)
        nfa, start, accept, next_index = star_nfa(nfa, start, accept, next_index)
        return nfa, start, accept, next_index
    else:
        raise ValueError(f"Unknown AST kind: {ast.kind}")


def nfa_to_dfa(nfa, start_state):
    dfa = {}
    dfa_start_state = tuple(
        set(eclosure(start_state))
    )  # DFA的初始状态是NFA开始状态的ε-闭包
    queue = deque([dfa_start_state])

    while queue:
        current_state = queue.popleft()
        dfa[current_state] = {}

        for symbol in get_symbols(nfa):
            next_state = set()

            for state in current_state:
                if state in nfa and symbol in nfa[state]:
                    next_state.update(nfa[state][symbol])

            if next_state:
                next_state = tuple(set(eclosure(next_state)))  # 计算新状态的ε-闭包
                dfa[current_state][symbol] = next_state

                if next_state not in dfa:
                    queue.append(next_state)

    return dfa


def eclosure(state):
    """
    计算给定状态集合的ε-闭包。
    """
    closure = list(state)
    stack = list(state)

    while stack:
        current_state = stack.pop()

        if current_state in nfa and "" in nfa[current_state]:
            next_states = nfa[current_state][""]
            for next_state in next_states:
                if next_state not in closure:
                    closure.append(next_state)
                    stack.append(next_state)

    return closure


def get_symbols(nfa):
    """
    获取NFA中的所有输入符号。
    """
    symbols = set()

    for state in nfa:
        if isinstance(nfa[state], dict):
            symbols.update(nfa[state].keys())

    return symbols


def re_to_nfa(regex):
    tokens = tokenize(regex)
    ast = parse(tokens)
    nfa, start, accept, _ = ast_to_nfa(ast)
    return nfa, start, accept


# Convert the regex pattern to an NFA
regex_pattern = "a(b|c)(b|c)*"
nfa, start_state, accept_state = re_to_nfa(regex_pattern)

# Convert the NFA to a DFA
dfa = nfa_to_dfa(nfa, str(start_state))

# Print the NFA and DFA
print("NFA:")
print(json.dumps(nfa))

print("\nDFA:")
for state in dfa:
    print(state, "->", dfa[state])


from automata.fa.nfa import NFA
from automata.fa.dfa import DFA

# Define the regex pattern
regex_pattern = "a(b|c)*"

# Convert the regex pattern to an NFA
nfa = NFA.from_regex(regex_pattern)
dfa = DFA.from_nfa(nfa)

# Print the NFA
print(nfa)
print(dfa)
