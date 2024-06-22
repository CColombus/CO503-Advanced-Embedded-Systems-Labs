#!/bin/bash

# Find all .elf files and store them in an array
elf_files=($(find . -type f -name '*.elf'))

# Define an array of CPU indices
cpu_indices=(
  0  # cpu_1b_p1
  1  # cpu_1b_p2
  2  # cpu_1b_p3
  3  # cpu_1c_p1
  4  # cpu_1c_p2
  5  # cpu_1c_p3
  6  # cpu_1d_p1
  7  # cpu_1d_p2
  8  # cpu_1d_p3
  9  # cpu_1e
)

# Check if the number of ELF files matches the number of CPU indices
if [ ${#elf_files[@]} -ne ${#cpu_indices[@]} ]; then
  echo "Error: The number of ELF files does not match the number of CPU indices."
  exit 1
fi

# Define the ANSI color codes
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Iterate over the elf files and execute the corresponding command
for i in "${!elf_files[@]}"
do
  elf_file="${elf_files[$i]}"
  cpu_index="${cpu_indices[$i]}"
  cmd="nios2-download -g -i $cpu_index $elf_file"
  echo -e "\n${GREEN}Executing: $cmd${NC}"
  $cmd
  if [ $? -ne 0 ]; then
    echo "Error: Command failed: $cmd"
    exit 1
  fi
done

echo -e "\n${GREEN}All commands executed successfully.${NC}"
