#!/bin/bash

# Usage: ./tests/run_tests.sh [sample_size] (-v|-s) [algorithm_name]
# Flags:		-s (silent output)
#				-v (verbose, shows beginning and end stack)
#				NONE (default push_swap output)
# Algorithms:	- insertion (insertion sort)
#				- selection (selection sort)
# Example:		"./tests/run_tests 100 -s selection" -> Runs selection sort on a stack filled with 100 random numbers without showing push_swap operations.


SRC_FILES=$(find srcs/ -name "*.c" ! -name "push_swap.c")

shuf -i 0-9999 -n $1 > args.txt
shift;

# make > /dev/null &&
# cc -Wall -Werror -Wextra -g -o test.out $SRC_FILES tests/*.c -Llibftprintf -lftprintf &&
# valgrind --leak-check=full --show-leak-kinds=all -s ./test.out $@ $(cat args.txt)

make > /dev/null &&
cc -Wall -Werror -Wextra -g -o test.out $SRC_FILES tests/*.c -Llibftprintf -lftprintf && ./test.out $@ $(cat args.txt)