#include "tests.h"

#define SILENT 		-1
#define PUSHSWAP	0
#define VERBOSE		1

int g_malloc_fail_counter = 0;
int g_malloc_fail_target = 0;
int g_malloc_fail_active = 0;

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

static void	test_algorithm(t_pushswap *data, int flag, void (*algorithm)(t_pushswap*))
{
	stack_init_a(data);
	stack_init_b(data);
	if (flag == VERBOSE)
		run_verbose(data, algorithm);
	else if (flag == SILENT)
		run_silent(data, algorithm);
	else
		algorithm(data);
}

int main(int argc, char **argv)
{
	int			flag;
	t_pushswap	*data;

	if (argc < 2)
		return (1);

	data = (t_pushswap *) ft_calloc(1, sizeof(t_pushswap));
	data->argc = --argc;
	data->argv = ++argv;

	if (ft_strncmp(*argv, "-d", 3) == 0)
	{
		test_disorder(data);
		delete_data(data);
		return (0);
	}

	if (ft_strncmp(*argv, "-v", 3) == 0)
	{
		flag = VERBOSE;
		data->argc--;
		data->argv++;
	}
	else if (ft_strncmp(*argv, "-s", 3) == 0)
	{
		flag = SILENT;
		data->argc--;
		data->argv++;
	}
	else
		flag = PUSHSWAP;

	if (ft_strncmp(*data->argv, "insertion", ft_strlen("insertion")) == 0)
		test_algorithm(data, flag, insertion_sort);
	else if (ft_strncmp(*data->argv, "selection", ft_strlen("selection")) == 0)
		test_algorithm(data, flag, selection_sort);
	else if (ft_strncmp(*data->argv, "bubble", ft_strlen("bubble")) == 0)
		test_algorithm(data, flag, bubble_sort);
	else if (ft_strncmp(*data->argv, "butterfly", ft_strlen("butterfly")) == 0)
		test_algorithm(data, flag, butterfly_sort);

	delete_data(data);
	return (0);
}
