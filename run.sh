#!/bin/bash

thread=1
if ! [ $# -eq 0 ]; then
    thread=$1
fi


input_folders=(multi multi-demand)

# Loop over each input file
for input_folder in "${input_folders[@]}"; do
    # Extract the base filename (without extension)
    # filename=$(basename -- "$input_file")
    # filename="${filename%.*}"

    # # Compile the corresponding C++ file using CMake
    # cmake -S . -B build 
    # cmake --build build 

    # Execute the compiled C++ program with the input file
    # echo "$input_file"

    # Specify the directory path
    directory="instances/"$input_folder

    # Use ls command to list all files in the directory
    files=$(ls "$directory")

    # Loop through each file and print its name
    for file in $files
    do
        
        # echo "$thread"
        ./build/build/bin/tsp -t "$input_folder" -n "$file" -c "$thread"
    done
    
done