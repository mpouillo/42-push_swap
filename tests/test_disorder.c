#include "../tests/tests.h"

void	test_disorder(int argc, char **argv)
{
	t_stack	*stack;
	int		disorder;

	stack = stack_create(argv + 1, argc - 1);
	disorder = compute_disorder(*stack);
	ft_printf("Disorder = %i.%.2i\n", disorder / 1000, disorder % 1000 / 10);
	stack_delete(stack);
}
