#!/bin/bash

# Define an array of commands
commands=(
  "nios2-download -g -i 0 ./CPU_1b_p1_sub_cpu_0.elf"
  "nios2-download -g -i 1 ./CPU_1b_p2_sub_cpu_0.elf"
  "nios2-download -g -i 2 ./CPU_1b_p3_sub_cpu_0.elf"
  "nios2-download -g -i 3 ./CPU_1c_p1_sub_cpu_0.elf"
  "nios2-download -g -i 4 ./CPU_1c_p2_sub_cpu_0.elf"
  "nios2-download -g -i 5 ./CPU_1c_p3_sub_cpu_0.elf"
  "nios2-download -g -i 6 ./CPU_1d_p1_sub_cpu_0.elf"
  "nios2-download -g -i 7 ./CPU_1d_p2_sub_cpu_0.elf"
  "nios2-download -g -i 8 ./CPU_1d_p3_sub_cpu_0.elf"
  "nios2-download -g -i 9 ./CPU_1e_sub_cpu_0.elf"
)

# Iterate over the commands and execute each one
for cmd in "${commands[@]}"
do
  echo "Executing: $cmd"
  $cmd
  if [ $? -ne 0 ]; then
    echo "Error: Command failed: $cmd"
    exit 1
  fi
done

echo "All commands executed successfully."
