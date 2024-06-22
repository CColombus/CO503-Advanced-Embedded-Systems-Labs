if [ -z "$1" ]; then
    echo "Usage: $0 <elf_file>";
    exit 1;
fi

intended_cpu=$(nios2-elf-query $1  --cpu_name);
node_list=$(nios2-elf-query $1 --jdi | grep '<node');

i_cpu_id=$(echo "$node_list" | grep "$intended_cpu" | awk -F '[:|]' '{print $2}');