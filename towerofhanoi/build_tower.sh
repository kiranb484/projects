#!/bin/bash

set -e

if [ $# -eq 0 ]; then
    echo "Compiling tower.cpp"
    g++ -std=c++17 tower.cpp -o tower

    echo "Running explain_stl"
    ./tower
else
    if [ $1 == "clean" ]; then
        echo "Cleaning up"
        rm -vf tower
    else
        echo "Unknown argument: $1"
    fi
fi
