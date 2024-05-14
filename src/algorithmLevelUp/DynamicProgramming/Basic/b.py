def regex_to_nfa(pattern):
    nfa = {}
    states = 0

    def add_transition(from_state, symbol, to_state):
        if from_state in nfa:
            if symbol in nfa[from_state]:
                nfa[from_state][symbol].append(to_state)
            else:
                nfa[from_state][symbol] = [to_state]
        else:
            nfa[from_state] = {symbol: [to_state]}

    def build_nfa(start, end, remaining_pattern):
        nonlocal states
        
        # base case
        if len(remaining_pattern) == 0:
            states += 1
            return [(start, end)]

        char = remaining_pattern[0]
        remaining_pattern = remaining_pattern[1:]
        new_start = start
        new_end = None

        # handle the OR operator (|)
        if len(remaining_pattern) > 0 and remaining_pattern[0] == '|':
            new_start = states
            pattern_after_or = remaining_pattern[1:]
            remaining_pattern = ''

            or_transitions = []
            or_transitions += build_nfa(new_start + 1, new_start + 2, pattern_after_or)
            or_transitions += build_nfa(new_start + 1, end, remaining_pattern)

            for transition in or_transitions:
                add_transition(start, None, transition[0])
                add_transition(transition[1], None, new_start + 2)

        # handle concatenation ('ab')
        if char != '|' and char != '*':
            new_end = states + 1
            states += 2
            
            # add transitions from start state to end state using the symbol
            add_transition(start, char, new_end)

            if len(remaining_pattern) > 0:
                # build NFA for remaining pattern
                remaining_transitions = build_nfa(new_end, end, remaining_pattern)
                
                for transition in remaining_transitions:
                    add_transition(new_end, None, transition[0])
                    add_transition(transition[1], None, end)

        # handle Kleene star ('*')
        if len(remaining_pattern) > 0 and remaining_pattern[0] == '*':
            add_transition(start, None, end)
            add_transition(start, None, states + 1)
            add_transition(states, None, end)
            add_transition(states, None, states + 1)
            states += 2
            remaining_pattern = remaining_pattern[1:]

        return [(new_start, new_end)] if new_start != start else []

    build_nfa(0, states + 1, pattern)
    
    if states not in nfa:
        nfa[states] = {}  # Initialize entry for state
        
    nfa[states][None] = [state + 1 for state in range(states)]
    
    return nfa

regex_pattern = 'a(b|c)*'
nfa = regex_to_nfa(regex_pattern)

print(nfa)
