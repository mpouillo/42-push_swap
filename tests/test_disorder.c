#include "../tests/tests.h"

void	test_disorder(t_stack *stack)
{
	int	disorder;

	disorder = compute_disorder(*stack);
	ft_printf("Disorder = %i.%.2i\n", disorder / 100, disorder % 100);
}
