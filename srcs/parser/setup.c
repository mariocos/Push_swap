/****************************************/
/*      (\__/)                          */
/*      (o^.^)                          */
/*     z(_(")_(")_                      */
/*                                      */
/*   Mariocos: push_swap revamped       */
/****************************************/

#include "../../push_swap.h"

static int	*ft_populate_list(int argc, char **argv, t_list *s)
{
	int	*list;
	int	i;

	i = 0;
	list = (int *)malloc(sizeof(int) * (argc - 1));
	s->a = list;
	if (!list)
		return (0);
	while (i < argc - 1)
	{
		list[i] = ft_atoi(argv[i + 1], s, argv);
		i++;
	}
	return (list);
}

static int	ft_check_params(int argc, char **argv)
{
	int	i;
	int	argc_i;

	argc_i = 1;
	while (argc_i < argc)
	{
		i = 0;
		if ((argv[argc_i][i] == '-'
			|| argv[argc_i][i] == '+' || argv[argc_i][i] == ' ')
			&& argv[argc_i][i + 1] == '\0')
			return (0);
		while (argv[argc_i][i] != '\0')
		{
			if (i == 0 && (argv[argc_i][i] == '-' || argv[argc_i][i] == '+'))
				i++;
			if (ft_isdigit(argv[argc_i][i]) == 0)
				return (0);
			i++;
		}
		argc_i++;
	}
	return (1);
}

static int	check_dupes(t_list *s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < s->a_len)
	{
		j = 0;
		flag = 0;
		while (j < s->a_len)
		{
			if (s->a[j] == s->a[i])
				flag++;
			if (flag > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_list	*setup(int argc, char **strs)
{
	t_list	*s;

	s = NULL;
	if (isarg(argc, strs) == 0)
		error_exit(s, strs);
	if (ft_check_params(argc, strs) == 0)
		error_exit(s, strs);
	s = (t_list *)calloc(sizeof(t_list), 1);
	if (!s)
		error_exit(s, strs);
	s->a = ft_populate_list(argc, strs, s);
	s->a_len = argc - 1;
	s->b_len = 0;
	s->b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!s->b)
		error_exit(s, strs);
	if (check_dupes(s) == 0)
		error_exit(s, strs);
	return (s);
}

t_list	*parse_input(int argc, char **argv)
{
	t_list	*s;
	char	*args;
	char	**strs;

	args = join_args(argv);
	strs = ft_split(args, ' ');
	free(args);
	s = setup(argc, strs);
	free_double_char(strs);
	return (s);
}