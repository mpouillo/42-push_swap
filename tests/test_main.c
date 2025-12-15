#include "../tests/tests.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc > 2)
		stack_a = stack_create(argv + 1, argc - 1);
	else
	{
		ft_printf("Creating empty stack (no arguments passed to the function)\n");
		stack_a = stack_create(NULL, 0);
	}
	rra(stack_a);

	test_disorder(stack_a);
	test_stack(stack_a);

	stack_delete(stack_a);
	return (0);
}
