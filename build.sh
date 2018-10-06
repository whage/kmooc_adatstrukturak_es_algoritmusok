#!/bin/bash

build_dir=./build

# create build dir if it doesn't exist
if [[ ! -d $build_dir ]]; then
    mkdir $build_dir
fi

# check arg count, run g++
if [[ $# -ne 1 ]]; then
    echo "usage: ./build.sh <source_file_name>"
    echo "the compiled files will be placed in $build_dir directory"
else
    g++ $1 -o $build_dir/${1%.*}
fi
