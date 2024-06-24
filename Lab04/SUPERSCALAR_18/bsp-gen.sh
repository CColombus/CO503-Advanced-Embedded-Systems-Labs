sopc_file=${1%/}
bsp_dir=${2%/}
src_dir=${3%/}
cpu_name=$4
current_dir=$(pwd)

# Input string
output=$(nios2-bsp-create-settings --sopc $sopc_file --cpu-name ?)

# echo "$output"

# Extract the list part from the string and remove the square brackets
list_str=$(echo "$output" | sed -e 's/.*\[\(.*\)\].*/\1/')

# echo "$list_str"

# Convert the comma-separated string to a list
cpu_array=(${list_str//,/ })

# Print the resulting array elements
# for cpu in "${cpu_array[@]}"; do
#     echo "$cpu"
# done

# Create a new array from array elements that contain the cpu_name
cpu_array_filtered=()
for cpu in "${cpu_array[@]}"; do
    if [[ $cpu == *"$cpu_name"* ]]; then
        cpu_array_filtered+=("$cpu")
    fi
done

# Print the resulting array elements
# for cpu in "${cpu_array_filtered[@]}"; do
#     echo "$cpu"
# done

# if the array is empty, or larger than 1, print an error message
if [[ ${#cpu_array_filtered[@]} -eq 0 ]]; then
    echo "Error: CPU name not found"
    exit 1
elif [[ ${#cpu_array_filtered[@]} -gt 1 ]]; then
    echo "Error: CPU name is ambiguous"
    for cpu in "${cpu_array_filtered[@]}"; do
        echo "$cpu"
    done
    exit 1
else
    echo "CPU name found: ${cpu_array_filtered[0]}"
fi 

cpu_name=${cpu_array_filtered[0]}
# remove any leading or trailing whitespace
cpu_name=$(echo $cpu_name | xargs)

echo "CPU name: $cpu_name"

# timer_name should be cpu_name remove "_sub_cpu_0" and add "_timer_0"
timer_name=$(echo $cpu_name | sed -e 's/_sub_cpu_0/_timer_0/')

nios2-bsp hal $bsp_dir $sopc_file --cpu-name $cpu_name --set hal.timestamp_timer $timer_name --set hal.enable_reduced_device_drivers 1 --set hal.enable_small_c_library 1 --set hal.enable_c_plus_plus 0 --set hal.enable_clean_exit 0 --set altera_avalon_jtag_uart_driver.enable_small_driver true --set hal.enable_lightweight_device_driver_api 1 --set hal.make.bsp_cflags_optimization "-O2"

# if the bsp generation was successful, print a success message
if [ $? -eq 0 ]; then
    echo "BSP generation successful"
else
    echo "BSP generation failed!"
    exit 1
fi

cd $bsp_dir
make

# if the compilation was successful, print a success message
if [ $? -eq 0 ]; then
    echo "BSP Compilation successful"
else
    echo "BSP Compilation failed!"
    exit 1
fi

cd $current_dir

# Now to create the app
nios2-app-generate-makefile --bsp-dir $bsp_dir --app-dir $src_dir --elf-name $cpu_name.elf --src-rdir $src_dir

cd $src_dir
make

# if the compilation was successful, print a success message
if [ $? -eq 0 ]; then
    echo "App Compilation successful"
else
    echo "App Compilation failed!"
    exit 1
fi