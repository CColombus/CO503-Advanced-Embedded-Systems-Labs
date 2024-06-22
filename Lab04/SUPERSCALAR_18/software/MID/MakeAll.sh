#!/bin/bash

# Define the directory to search
SEARCH_DIR=${1:-.}

# Define the ANSI color codes
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Find all makefiles not in directories ending with "_bsp"
find "$SEARCH_DIR" -type d -name '*_bsp' -prune -o -type f -name 'Makefile' -print | while read -r makefile; do
  makefile_dir=$(dirname "$makefile")
  echo -e "\n${GREEN}Running make in $makefile_dir${NC}"
  (cd "$makefile_dir" && make)
done
