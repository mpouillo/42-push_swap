#include "tests.h"

#define SILENT 		-1
#define PUSHSWAP	0
#define VERBOSE		1

static void	run_silent(t_pushswap *data, void (*algorithm)(t_pushswap *))
{
	int		original_stdout;
	int		dev_null;

	fflush(stdout);
	original_stdout = dup(STDOUT_FILENO);
	dev_null = open("/dev/null", O_WRONLY);
	dup2(dev_null, STDOUT_FILENO);
	close(dev_null);
	algorithm(data);
	fflush(stdout);
	dup2(original_stdout, STDOUT_FILENO);
	close(original_stdout);
	ft_printf("Total operations: %i\n", data->total_ops);
}

static void	run_verbose(t_pushswap *data, void (*algorithm)(t_pushswap *))
{
	ft_printf("UNSORTED STACK:\n");
	print_stack(data->a);
	algorithm(data);
	ft_printf("SORTED STACK:\n");
	print_stack(data->a);
	ft_printf("Total operations: %i\n", data->total_ops);
}

static void	test_algorithm(int argc, char **argv, int flag, void (*algorithm)(t_pushswap*))
{
	t_pushswap *data;

	data = (t_pushswap *) ft_calloc(1, sizeof(t_pushswap));
	data->a = stack_create(argv + 1, argc - 1);
	data->b = stack_create(NULL, 0);
	if (flag == VERBOSE)
		run_verbose(data, algorithm);
	else if (flag == SILENT)
		run_silent(data, algorithm);
	else
		algorithm(data);
	delete_data(data);
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
	else if (ft_strncmp(argv[1], "bubble", ft_strlen("bubble")) == 0)
		test_algorithm(argc - 1, argv + 1, flag, bubble_sort);

	return (0);
}
