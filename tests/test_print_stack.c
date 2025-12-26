#include "tests.h"

void	print_stack_p(t_stack *stack)
{
	t_node	*cur;

	cur = stack->head;
	ft_printf("+-----------------------------------------------------------+\n");
	ft_printf("| %-14s -> %-21s -> %-14s |\n", "PREV", "CURRENT (item)", "NEXT");
	ft_printf("+-----------------------------------------------------------+\n");
	if (!cur)
		ft_printf("| %-55s |\n", "EMPTY");
	while (cur)
	{
		ft_printf("| %-14p -> %-14p (%-4i) -> %-14p |\n", cur->prev, cur, cur->item, cur->next);
		cur = cur->next;
	}
	ft_printf("+-----------------------------------------------------------+\n");
}

void	print_line(int length)
{
	ft_printf("+");
	for (int i = 0; i < length + 2; i++)
		ft_printf("-");
	ft_printf("+\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*cur;
	int		width;

	width = 10;
	cur = stack->head;
	print_line(width);
	if (!cur)
		ft_printf("|%*s|\n", width, " EMPTY ");
	while (cur)
	{
		ft_printf("| %*i |\n", width, cur->item);
		cur = cur->next;
	}
	print_line(width);
}
