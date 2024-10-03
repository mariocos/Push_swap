/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:39:00 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 13:08:14 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_b_help(t_list *s, int *new_a, int *new_b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < s->a_len)
		new_a[i++] = s->a[j++];
	new_b[0] = s->a[0];
	i = 0;
	j = 1;
	while (i < s->b_len)
		new_b[j++] = s->b[i++];
	free(s->a);
	free(s->b);
	s->a = new_a;
	s->b = new_b;
	s->a_len--;
	s->b_len++;
}

void	ft_pb(t_list *s)
{
	int	*new_a;
	int	*new_b;

	new_a = malloc(sizeof(int) * (s->a_len - 1));
	new_b = malloc(sizeof(int) * (s->b_len + 1));
	if (!new_a || !new_b)
		error_exit(s);
	pop_b_help(s, new_a, new_b);
	write (1, "pb\n", 3);
}

void	pop_a_help(t_list *s, int *new_a, int *new_b)
{
	int	i;
	int	j;

	new_a[0] = s->b[0];
	i = 0;
	j = 1;
	while (i < s->a_len)
		new_a[j++] = s->a[i++];
	i = 0;
	j = 1;
	while (j < s->b_len)
		new_b[i++] = s->b[j++];
	free(s->a);
	free(s->b);
	s->a = new_a;
	s->b = new_b;
	s->a_len++;
	s->b_len--;
}

void	ft_pa(t_list *s)
{
	int	*new_a;
	int	*new_b;

	new_a = malloc(sizeof(int) * (s->a_len + 1));
	new_b = malloc(sizeof(int) * (s->b_len - 1));
	if (!new_a || !new_b)
		error_exit(s);
	pop_a_help(s, new_a, new_b);
	write(1, "pa\n", 3);
}
