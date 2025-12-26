#include "tests.h"

#define SILENT 		-1
#define PUSHSWAP	0
#define VERBOSE		1

int	run_silent(t_stack *a, t_stack *b, size_t (*algorithm)(t_stack *, t_stack *))
{
	int		original_stdout;
	int		dev_null;
	size_t	ret;

	fflush(stdout);
	original_stdout = dup(STDOUT_FILENO);
	dev_null = open("/dev/null", O_WRONLY);
	dup2(dev_null, STDOUT_FILENO);
	close(dev_null);
	ret = algorithm(a, b);
	fflush(stdout);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	return (ret);
}

int	run_verbose(t_stack *a, t_stack *b, size_t (*algorithm)(t_stack *, t_stack *))
{
	size_t	ret;

	ft_printf("UNSORTED STACK:\n");
	print_stack(a);
	ret = algorithm(a, b);
	ft_printf("SORTED STACK:\n");
	print_stack(a);
	return (ret);
}

static void	test_algorithm(int argc, char **argv, int flag, size_t (*algorithm)(t_stack *, t_stack*))
{
	t_stack	*a;
	t_stack	*b;

	a = stack_create(argv + 1, argc - 1);
	b = stack_create(NULL, 0);
	if (flag == VERBOSE)
		ft_printf("Total moves: %i\n", run_verbose(a, b, algorithm));
	else if (flag == SILENT)
		ft_printf("Total moves: %i\n", run_silent(a, b, algorithm));
	else
		algorithm(a, b);
	stack_delete(a);
	stack_delete(b);
}

int main(int argc, char **argv)
{
	int	flag;

	if (argc < 2)
		return (1);

	if (ft_strncmp(argv[1], "-d", ft_strlen("-d")) == 0)
	{
		test_disorder(argc, argv);
		return (0);
	}
	else if (ft_strncmp(argv[1], "-v", ft_strlen("-v")) == 0)
	{
		flag = VERBOSE;
		argc -= 1;
		argv += 1;
	}
	else if (ft_strncmp(argv[1], "-s", ft_strlen("-s")) == 0)
	{
		flag = SILENT;
		argc -= 1;
		argv += 1;
	}
	else
		flag = PUSHSWAP;

	if (ft_strncmp(argv[1], "insertion", ft_strlen("insertion")) == 0)
		 test_algorithm(argc - 1, argv + 1, flag, insertion_sort);
	else if (ft_strncmp(argv[1], "selection", ft_strlen("selection")) == 0)
		test_algorithm(argc - 1, argv + 1, flag, selection_sort);

	return (0);
}
