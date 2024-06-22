# 
# TODO: First gen the header files from "sopc-create-header-files"
# TODO: Then grep it to get unique sorted list of FIFO BASE addresses
# TODO: grep -rih " FIFO.*BASE" .\subheads | sort | uniq >> basemap.h
# TODO: Add library definitions to the header file
# TODO: Now run the script to generate the output.h file

import re
from collections import defaultdict
from icecream import ic

# Function to read input data from a file
def read_data_from_file(file_path):
    with open(file_path, 'r') as file:
        return file.read()

# Function to parse the input data
def parse_data(data):
    # Updated pattern to match queue identifiers with numbers and underscores
    pattern = re.compile(r'#define (FIFO_[0-9A-Z_]+_[A-Z_]+_BASE)\s+(0x[0-9a-fA-F]+)')
    matches = pattern.findall(data)
    
    # ic(matches)

    queues = defaultdict(lambda: {"IN": None, "OUT": None, "CSR": None})

    for match in matches:
        full_name, address = match
        queue = re.search(r'FIFO_(\d\w|Q_\d)_', full_name).group(1)
        # ic(full_name)
        if "IN_BASE" in full_name:
            queues[queue]["IN"] = full_name
        elif "OUT_BASE" in full_name:
            queues[queue]["OUT"] = full_name
        elif "IN_CSR_BASE" in full_name:
            queues[queue]["CSR"] = full_name

    return queues

# Function to generate the output
def generate_output(queues):
    header = """
#ifndef Q_MEM_OBJ_DEF_H
#define Q_MEM_OBJ_DEF_H

#include "q_mem_obj.h"
#include "q_mem_map.h"
"""

    footer = """
#endif // Q_MEM_OBJ_DEF_H
"""

    body = ""
    for i, (queue, addresses) in enumerate(sorted(queues.items()), start=1):
        ic(queue, addresses)
        qname = queue.replace("_", "").replace("Q","").lower()
        mem_base_in = addresses["IN"]
        mem_base_out = addresses["OUT"]
        ctrl_base = addresses["CSR"]
        body += f"""
Queue q{qname} = {{
    .mem_base_in = {mem_base_in},
    .mem_base_out = {mem_base_out},
    .ctrl_base = {ctrl_base}
}};
"""

    return header + body + footer

# Main function
def main(input_file):
    data = read_data_from_file(input_file)
    queues = parse_data(data)
    output = generate_output(queues)
    # put output to a file
    with open('q_mem_obj_def.h', 'w') as file:
        file.write(output)
        
    begin = """
#ifndef Q_MEM_MAP_H
#define Q_MEM_MAP_H

"""
    end = """

#endif // Q_MEM_MAP_H
"""
    
    with open('q_mem_map.h', 'w') as file:
        file.write(begin+data+end)

# Run the main function with the input file path
input_file = 'basemap.h'
main(input_file)
