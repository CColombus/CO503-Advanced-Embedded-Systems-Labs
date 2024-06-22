# if $1 is not provided, then error
if [ -z "$1" ]; then
    echo "Usage: $0 <elf_file>";
    exit 1;
fi

jtag_output=$(jtagconfig -n);
jtag_list=$(echo "$jtag_output" | grep 'Node' | awk '{print $2}');
node_list=$(nios2-elf-query $1 --jdi | grep '<node');

# Function to extract hpath elements
extract_hpath_elements() {
    local hpath=$1;
    local cpu=$(echo $hpath | awk -F '[:|]' '{print $4}');
    # return the value of cpu and not echo
    echo $cpu;
    # echo -e "\t$cpu";
}

for item in $jtag_list; do
    line=$(echo "$jtag_output" | grep $item);
    i1=$(echo $line | awk '{print $5}');
    d1=$(echo $line | awk '{print $3}');
    d2=$(echo $line | awk '{print $4}');
    id=$(echo $line | awk '{print $2}');
    id_s=$(echo $id | sed 's/^0*//');
    text=$(echo "$node_list" | grep "$id_s");
    cpu=$(extract_hpath_elements "$text");
    echo -e "$i1\t$d1 $d2--->$cpu";
    # print like a table without tabs but using padding
done