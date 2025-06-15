#!/bin/zsh

# Function to check arguments
check_args() {
    if [ $# -ne 1 ]; then
        echo "Usage: ./run_sim.sh <testbench_file.v>"
        echo "   or: ./run_sim.sh clean"
        exit 1
    fi
}

# Function to setup file names
setup_files() {
    TESTBENCH=$1
    OUTPUT="${TESTBENCH%.*}.vvp"
    
    # Extract VCD filename from the testbench file
    VCD=$(grep '\$dumpfile' "$TESTBENCH" | sed -E 's/.*\$dumpfile\("(.*)"\);.*/\1/')
    if [ -z "$VCD" ]; then
        echo "Note: No VCD dump found in testbench"
    else
        echo "VCD file: $VCD"
    fi
}

# Function to compile with iverilog
compile_verilog() {
    echo "Running iverilog..."
    iverilog -o $OUTPUT $TESTBENCH
    if [ $? -ne 0 ]; then
        echo "Error: iverilog compilation failed"
        exit 1
    fi
}

# Function to run simulation
run_simulation() {
    echo "Running vvp simulation..."
    vvp $OUTPUT
    if [ $? -ne 0 ]; then
        echo "Error: vvp simulation failed"
        exit 2
    fi
}

# Function to open waveform
open_waveform() {
    if [ ! -z "$VCD" ]; then
        if [ -f "$VCD" ]; then
            echo "Opening GTKWave..."
            gtkwave $VCD &
            if [ $? -ne 0 ]; then
                echo "Error: GTKWave failed to open"
                exit 4
            fi
        else
            echo "Warning: VCD file $VCD was not generated"
        fi
    else
        echo "Skipping waveform view as no VCD dump was specified in testbench"
    fi
}

# Function to clean up generated files
clean_files() {
    echo "Cleaning up generated files..."
    # Use nullglob to handle case when no files match
    setopt nullglob
    for file in *.vvp *.vcd; do
        if [ -f "$file" ]; then
            echo "Removing $file"
            rm "$file"
        fi
    done
    unsetopt nullglob
    echo "Clean complete"
}

# Main function to orchestrate the simulation process
main() {
    if [ "$1" = "clean" ]; then
        clean_files
    else
        check_args "$@"
        # Clean first before running new simulation
        clean_files
        setup_files "$1"
        compile_verilog
        run_simulation
        open_waveform
    fi
}

# Execute main function with all arguments
main "$@"
