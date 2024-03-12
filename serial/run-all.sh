#!/bin/bash

# Compile the program
make clean && make

# Define configurations
configurations=(
    "1000 64 0.4 0"
    "200 128 0.5 1000"
    "10 512 0.4 0"
    "3 1024 0.4 100"
)

# Execute each configuration without setting OMP_NUM_THREADS
for config in "${configurations[@]}"; do
    echo "Executing configuration: $config"
    ./life3d $config
    echo "Execution completed."
done
