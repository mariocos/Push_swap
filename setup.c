/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:21 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 14:20:48 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_list *s)
{
	if (s)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		free (s);
	}
	write (2, "Error\n", 6);
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

int	check_dupes(t_list *s)
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

t_list	*setup(int argc, char **argv)
{
	t_list	*s;

	s = NULL;
	if (isarg(argc, argv) == 0)
		error_exit(s);
	if (ft_check_params(argc, argv) == 0)
		error_exit(s);
	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		error_exit(s);
	s->a = ft_populate_list(argc, argv, s);
	s->a_len = argc - 1;
	s->b_len = 0;
	s->b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!s->b)
		error_exit(s);
	if (check_dupes(s) == 0)
		error_exit(s);
	return (s);
}
