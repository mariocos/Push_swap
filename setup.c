#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	Error_exit(t_list *s)
{
	if (s)
	{
		if (s->A)
			free(s->A);
		if (s->B)
			free(s->B);
		free (s);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	*ft_populate_list(int argc, char **argv, t_list *s)
{
	int	*list;
	int	i;

	i = 0;
	list = (int *)malloc(sizeof(int) * (argc - 1));
	if (!list)
		return (0);
	while (i < argc - 1)
	{
		list[i] = ft_atoi(argv[i + 1], s);
		i++;
	}
	return (list);
}

int	ft_check_params(int argc, char **argv)
{
	int i;
	int argc_i;

	argc_i = 1;
	while (argc_i < argc)
	{
		i = 0;

		if ((argv[argc_i][i] == '-' || argv[argc_i][i] == '+' || argv[argc_i][i] == ' ')
			&& argv[argc_i][i + 1] == '\0')//unsure if numbers should be allowed to start with a +
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


int	check_dupes(t_list *s)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < s->A_len)
	{
		j = 0;
		flag = 0;
		while (j < s->A_len)
		{
			if (s->A[j] == s->A[i])
				flag++;
			if (flag > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_list	*setup(int argc, char **argv)
{
	t_list	*s;

	s = NULL;
	if (isarg(argc, argv) == 0)
		Error_exit(s);
	if (ft_check_params(argc, argv) == 0)
		Error_exit(s);
	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		Error_exit(s);
	s->A = ft_populate_list(argc, argv, s);
	s->A_len = argc - 1;
	s->B_len = 0;
	s->B = (int *)malloc(sizeof(int) * (argc - 1));
	if (!s->B)
		Error_exit(s);
	if (check_dupes(s) == 0)
		Error_exit(s);
	return (s);
}
