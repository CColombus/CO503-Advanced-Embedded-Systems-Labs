# src_dir 1st arg
# dst_dir 2nd arg

current_dir=$(pwd)
sopc_file=${1%/}
dst_dir=${2%/}
lib_dir=${3%/}
src_dir=${4%/}
cpu_name=$(echo $src_dir | rev | cut -d'/' -f1 | rev)

echo "Creating directories for CPU: $cpu_name"

mkdir -p $dst_dir/$cpu_name/$cpu_name
mkdir -p $dst_dir/$cpu_name/lib
mkdir -p $dst_dir/$cpu_name'_bsp'

# for each file in src_dir create a hard link in dst_dir/cpu_name/cpu_name/
for file in $(ls $src_dir)
do
    ln $src_dir/$file $dst_dir/$cpu_name/$cpu_name/$file
done

# for each file in lib_dir create a hard link in dst_dir/cpu_name/lib/
for file in $(ls $lib_dir)
do
    ln $lib_dir/$file $dst_dir/$cpu_name/lib/$file
done

cd $current_dir

echo -n "Directories created: $dst_dir/$cpu_name/$cpu_name/ $dst_dir/$cpu_name/lib/ $dst_dir/$cpu_name"
echo "_bsp"

app_dir=$dst_dir/$cpu_name
bsp_dir=$dst_dir/$cpu_name'_bsp'
sopc_file=$sopc_file
cpu_name=$cpu_name

./bsp-gen.sh $sopc_file $bsp_dir $app_dir $cpu_name