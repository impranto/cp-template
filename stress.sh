#!/bin/bash

# Usage: ./stress 100

num_tests=$1

# Compile generator, brute, optimized
echo "Compiling..."
g++ -O2 -std=c++17 generator.cpp -o generator || { echo "Compilation failed: generator.cpp"; exit 1; }
g++ -O2 -std=c++17 brute.cpp -o brute || { echo "Compilation failed: brute.cpp"; exit 1; }
g++ -O2 -std=c++17 optimized.cpp -o optimized || { echo "Compilation failed: optimized.cpp"; exit 1; }

echo "Starting stress test with $num_tests tests..."

for ((t=1; t<=num_tests; t++))
do
    echo "Test $t"

    # Generate test case
    ./generator > input.txt

    # Run brute force solution
    ./brute < input.txt > brute_output.txt

    # Run optimized solution
    ./optimized < input.txt > optimized_output.txt

    # Compare outputs
    diff -w brute_output.txt optimized_output.txt > diff.txt

    if [ $? -ne 0 ]; then
        echo "Wrong Answer on test $t ❌"
        echo "Input:"
        cat input.txt
        echo "Brute Output:"
        cat brute_output.txt
        echo "Optimized Output:"
        cat optimized_output.txt
        exit 1
    else
        echo "OK ✅"
    fi
done

echo "All tests passed! 🎉"
