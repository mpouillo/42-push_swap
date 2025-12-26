#ifndef TESTS_H
# define TESTS_H

#include "../includes/push_swap.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	print_stack(t_stack *stack);
void	test_stack(t_stack *stack);
void	test_disorder(int argc, char **argv);

#endif
