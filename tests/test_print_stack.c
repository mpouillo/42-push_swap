#include "tests.h"

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	cur = stack->head;
	ft_printf("Printing current stack:\n");
	ft_printf("+------------------------------------------+\n");
	ft_printf("| %-9s -> %-9s -> %-9s |\n", "PREV", "CURRENT (item)", "NEXT");
	ft_printf("+------------------------------------------+\n");
	if (!cur)
		ft_printf("| %-40s |\n", "EMPTY");
	while (cur)
	{
		ft_printf("| %-9p -> %-9p (%-2i) -> %-9p |\n", cur->prev, cur, cur->item, cur->next);
		cur = cur->next;
	}
	ft_printf("+------------------------------------------+\n");
}
