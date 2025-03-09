/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:35:31 by mariocos          #+#    #+#             */
/*   Updated: 2025/03/09 14:13:21 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all(t_list *s)
{
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
	free(s);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*s;

	s = NULL;
	if (argc == 1)
		return (1);
	else
		s = parse_input(argc, argv);
	if (!s)
		error_exit(s, NULL);
	if (sort_check(s->a, s->a_len) == 1)
		free_all(s);
	else if (s->a_len > 3)
		ft_full_sort(s);
	else if (s->a_len == 3)
		ft_sort_three(s);
	else if (s->a_len == 2 && sort_check(s->a, s->a_len) == 0)
		write(1, "sa\n", 3);
	free_all(s);
	return (1);
}
