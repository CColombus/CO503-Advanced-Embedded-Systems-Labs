# if run with param -make, then make all the folders and files
# if run without param, then run all the main.exe files

# Check for -make param and assign to $make value as bool
$make = $args[0] -eq "-make"
# get current directory
$loc = (pwd).Path

# Goto 1a_parent folder and run main.exe
cd "$loc/1a_parent"
# if $make is true, run make all
# pwd
if ($make) { make all }
else {./main.exe}

# Goto 1b_parent/ 1b_p1,p2,p3 folders and run main.exe
cd "$loc/1b_parent"
# pwd
if ($make)
{
    # Run make all in each p1,p2,p3 folders
    cd ./1b_p1 && make all
    cd ../1b_p2 && make all
    cd ../1b_p3 && make all
}else {
    ./1b_p1/main.exe
    ./1b_p2/main.exe
    ./1b_p3/main.exe
}

# Goto 1c_parent/ 1c_p1,p2,p3 folders and run main.exe
cd "$loc/1c_parent"
# pwd
if ($make)
{
    # Run make all in each p1,p2,p3 folders
    cd ./1c_p1 && make all
    cd ../1c_p2 && make all
    cd ../1c_p3 && make all
}else {
    ./1c_p1/main.exe
    ./1c_p2/main.exe
    ./1c_p3/main.exe
}

# Goto 1d_parent/ 1d_p1,p2,p3 folders and run main.exe
cd "$loc/1d_parent"
# pwd
if ($make)
{
    # Run make all in each p1,p2,p3 folders
    cd ./1d_p1 && make all
    cd ../1d_p2 && make all
    cd ../1d_p3 && make all
}else {
    ./1d_p1/main.exe
    ./1d_p2/main.exe
    ./1d_p3/main.exe
}

# Goto 1e_parent folder and run main.exe
cd "$loc/1e_parent"
# pwd
if ($make) { make all }
else { ./main.exe }

# Goto 1f_parent folder and run main.exe
cd "$loc/1f_parent"
# pwd
if ($make) { make all }
else { ./main.exe }

cd ..