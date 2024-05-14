from collections import deque

def nfa_to_dfa(nfa, start_state):
    dfa = {}
    dfa_start_state = tuple(set(eclosure(start_state)))  # DFA的初始状态是NFA开始状态的ε-闭包
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
        
        if current_state in nfa and None in nfa[current_state]:
            next_states = nfa[current_state][None]
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


# 以下是一个简单的NFA示例
nfa = {
    '0':{'a':['1']},
    '1':{None:['2']},
    '2':{None:['3','9']},
    '3':{None:['4','6']},
    '4':{'b':['5']},
    '6':{'c':['7']},
    '5':{None:['8']},
    '7':{None:['8']},
    '8':{None:['3','9']}
}

start_state = '0'

# 将NFA转换为DFA
dfa = nfa_to_dfa(nfa, start_state)

# 打印DFA
for state in dfa:
    print(state, '->', dfa[state])
