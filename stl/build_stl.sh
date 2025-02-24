#!/bin/bash

set -e

if [ $# -eq 0 ]; then
    echo "Compiling explain_stl.cpp"
    g++ -std=c++17 explain_stl.cpp -o explain_stl

    echo "Running explain_stl"
    ./explain_stl
else
    if [ $1 == "clean" ]; then
        echo "Cleaning up"
        rm -vf explain_stl
    else
        echo "Unknown argument: $1"
    fi
fi
