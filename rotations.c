/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:04 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 15:19:09 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list *list)
{
	int	i;
	int	j;
	int	hold_a;
	int	hold_b;

	i = 0;
	j = 1;
	hold_a = list->a[0];
	hold_b = list->b[0];
	if (list->a_len > 1)
	{
		while (j < list->a_len)
			list->a[i++] = list->a[j++];
		list->a[j - 1] = hold_a;
	}
	i = 0;
	j = 1;
	if (list->b_len > 1)
	{
		while (j < list->b_len)
			list->b[i++] = list->b[j++];
		list->b[j - 1] = hold_b;
	}
	write (1, "rr\n", 3);
}

void	ft_rrr(t_list *list)
{
	int	i;
	int	j;
	int	hold_a;
	int	hold_b;

	hold_a = list->a[list->a_len - 1];
	hold_b = list->b[list->b_len - 1];
	i = list->a_len - 1;
	j = list->a_len - 2;
	if (list->a_len > 1)
	{
		while (i > 0)
			list->a[i--] = list->a[j--];
		list->a[0] = hold_a;
	}
	i = list->b_len - 1;
	j = list->b_len - 2;
	if (list->b_len > 1)
	{
		while (i > 0)
			list->b[i--] = list->b[j--];
		list->b[0] = hold_b;
	}
	write (1, "rrr\n", 4);
}

void	ft_fast_rotate_a(t_list *s)
{
	int	min_index;
	int	a_moves;

	min_index = ft_find_min(s->a, s->a_len);
	a_moves = ft_move_calc(min_index, s->a_len);
	ft_do_moves(s, a_moves, 0);
}
