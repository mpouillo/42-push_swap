#include "../tests/tests.h"

void	test_disorder(t_pushswap *data)
{
	int		disorder;

	stack_init_a(data);
	disorder = compute_disorder(*data->a);
	ft_printf("Disorder = %i.%.2i\n", disorder / 1000, disorder % 1000 / 10);
	stack_delete(data->a);
}
