#!/bin/bash

SRC_FILES=$(find srcs/ -name "*.c" ! -name "push_swap.c")

make &&
cc -Wall -Werror -Wextra -g -o test.out $SRC_FILES tests/*.c -Llibftprintf -lftprintf \
&& valgrind -s --leak-check=full --show-leak-kinds=all ./test.out $@ \
&& rm ./test.out
