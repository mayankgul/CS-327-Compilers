import re

def generate_c_header(output_file):
    with open(output_file, 'r') as f:
        content = f.read()

    # Split into states
    states = re.split(r'\nstate (\d+)\n', content, flags=re.IGNORECASE)
    
    terminals = set()
    non_terminals = set()
    table_data = {}

    for i in range(1, len(states), 2):
        state_id = int(states[i])
        body = states[i+1]
        table_data[state_id] = {}
        
        # Match Actions (Terminals: shift, reduce, accept)
        # Matches: IDENTIFIER  shift, and go to state 5
        for match in re.finditer(r'^\s{4}(\S+)\s+(shift, and go to state \d+|reduce using rule \d+|accept)', body, re.MULTILINE):
            symbol, action = match.groups()
            if symbol == "$end": symbol = "EOF"
            terminals.add(symbol)
            
            clean_action = ""
            if "shift" in action:
                clean_action = "S" + action.split()[-1]
            elif "reduce" in action:
                clean_action = "R" + action.split()[-1]
            elif "accept" in action:
                clean_action = "ACC"
            
            table_data[state_id][symbol] = clean_action

        # Match Gotos (Non-terminals)
        # Matches: expression  go to state 10
        for match in re.finditer(r'^\s{4}(\S+)\s+go to state (\d+)', body, re.MULTILINE):
            symbol, target = match.groups()
            if symbol not in terminals: # Ensure it's a non-terminal
                non_terminals.add(symbol)
                table_data[state_id][symbol] = target

    sorted_terms = sorted(list(terminals))
    sorted_non_terms = sorted(list(non_terminals))
    num_states = max(table_data.keys()) + 1

    with open('table_data.h', 'w') as f:
        f.write(f"#define NUM_STATES {num_states}\n")
        f.write(f"#define NUM_TERMS {len(sorted_terms)}\n")
        f.write(f"#define NUM_NON_TERMS {len(sorted_non_terms)}\n\n")
        
        f.write("const char* terminals[] = {" + ", ".join([f'"{t}"' for t in sorted_terms]) + "};\n")
        f.write("const char* non_terminals[] = {" + ", ".join([f'"{n}"' for n in sorted_non_terms]) + "};\n\n")
        
        f.write(f"const char* parsing_table[NUM_STATES][{len(sorted_terms) + len(sorted_non_terms)}] = {{\n")
        all_symbols = sorted_terms + sorted_non_terms
        for s in range(num_states):
            row = []
            for sym in all_symbols:
                val = table_data.get(s, {}).get(sym, "")
                row.append(f'"{val}"')
            f.write("    {" + ", ".join(row) + "},\n")
        f.write("};\n")
    print(f"Success! table_data.h generated with {num_states} states.")

generate_c_header('yapl_before_removing_conflicts.output')