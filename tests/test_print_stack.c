#include "tests.h"

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	cur = stack->head;
	ft_printf("Printing current stack:\n");
	ft_printf("#--------------------------------------------#\n");
	ft_printf("| %-10s -> %-10s -> %-10s |\n", "PREV", "CURRENT (item)", "NEXT");
	ft_printf("#--------------------------------------------#\n");
	if (!cur)
		ft_printf("| %-42s |\n", "EMPTY");
	while (cur)
	{
		ft_printf("| %-10p -> %-10p (%i) -> %-10p |\n", cur->prev, cur, cur->item, cur->next);
		cur = cur->next;
	}
	ft_printf("#--------------------------------------------#\n");
}
