#!/bin/bash

sopc_file=${1%/}
dst_dir=${2%/}
lib_dir=${3%/}
top_parent_dir=${4%/}
current_dir=$(pwd)

# Check if the home directory argument is provided
# if [ $# -ne 1 ]; then
#     echo "Usage: $0 <top_parent_directory>"
#     exit 1
# fi

# Assign the home directory argument to a variable and remove trailing slash if present


# List of parent directories (you can modify this list)
PARENT_DIRS=("1b_parent" "1c_parent" "1d_parent" "1e_parent")

SUBDIRS=()

# Check if each parent directory exists and list subdirectories
for PARENT in "${PARENT_DIRS[@]}"; do
    PARENT_PATH="$top_parent_dir/$PARENT"
    
    if [ -d "$PARENT_PATH" ]; then
        SUBDIRS+=($(find "$PARENT_PATH" -mindepth 1 -type d))
    else
        echo "Directory $PARENT_PATH does not exist."
        echo
    fi
done


# Print all collected subdirectories
echo "Confirm batch build for following directories:"
for SUBDIR in "${SUBDIRS[@]}"; do
    echo "  $SUBDIR"
done

echo -n "Do you want to build all? (y/n)"
read answer

# Define the ANSI color codes
GREEN='\033[0;32m'
NC='\033[0m' # No Color

if [ "$answer" == "y" ]; then
    for SUBDIR in "${SUBDIRS[@]}"; do
        echo -e "\n${GREEN}Sourcing $SUBDIR:${NC}\n"
        cd $current_dir
        ./dir-auto.sh $sopc_file $dst_dir $lib_dir $SUBDIR

        # if the bsp generation was successful, print a success message
        if [ $? -eq 0 ]; then
            echo -e "\n${GREEN}ALL OKAY!${NC}\n"
        else
            echo "SOMETHING BAD HAPPEND!"
            exit 1
        fi
    done
fi