# Recommended command to run tests.
# Make sure to run this from within your ft_printf folder.
# Change the location of gemini_tests.c and your .c source files if needed.

make \
&& cc -o test.out -g -O0 -Dmalloc=test_malloc -Dft_calloc=test_calloc tests/gemini_tests.c srcs/*.c libft/libft.a \
&& valgrind --leak-check=full --show-leak-kinds=all ./test.out \
&& cc -o test.out -g -O0 -Dmalloc=test_malloc -Dft_calloc=test_calloc tests/test_undefined.c -L. -lftprintf \
&& valgrind ./test.out \
&& rm test.out \
&& make fclean