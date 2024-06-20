# Lab 04 - Pipeplined JPEG Encorder

## Folder Structure

- `software_simulated_pipline`
  - Software simulation of a pipelined jpeg encorder using file queues
- `HARD_PREP`
  - Conversion of `software_simulated_pipeline` into hardware compatible codebase using interfaces and OOP concepts.
- `HARDWARE`
  - Hardware implementation of single pipeline jpeg encorder using On-Chip Memory Blocks as RAM and Queues (Done in Quartus II 13.1)
- `SUPERSCALAR_simulated_pipline`
  - Software simulation of a optimized parallel pipelined jpeg encorder using multiple processors and file queues for each stage.
- `BASELINE_18`
  - Hardware implementation of single pipelined jpeg encorder using SDRAM as RAM for every processors and On-chip memory blocks as Queues (Done in Quartus Prime Lite 18.1)
- `MEM_MAP_GEN`
  - Python automation scripts for generating Memory address definitions for hardware devices (i.e. queues) with the help of `sopcinfo-header` tool.