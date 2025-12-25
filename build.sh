#!/bin/bash

rm -rf out/build/*
echo "Running CMake Configure"
cmake -S . \
    -B out/build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1 

echo "Building Project"
cmake --build out/build

echo "Build Complete"

    
