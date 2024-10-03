/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:28:11 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 12:57:45 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prepare_to_pop(t_list *s, int b_index)
{
	int	a_moves;
	int	b_moves;
	int	a;

	b_moves = ft_move_calc(b_index, s->b_len);
	a = ft_move_calc(ft_target_index(s->a, s->a_len, s->b[b_index]), s->a_len);
	a_moves = a;
	if (a_moves * b_moves > 0)
		ft_coordinate_moves(s, a_moves, b_moves);
	else
		ft_do_moves(s, a_moves, b_moves);
}

void	ft_sort_back(t_list *s)
{
	int	rots;

	rots = 3;
	while (s->b_len > 0)
	{
		while (rots > 0 && s->b[0] < s->a[s->a_len - 1])
		{
			ft_rra(s);
			rots--;
		}
		ft_pa(s);
	}
	if (rots > 0)
	{
		ft_rra(s);
		rots--;
	}
}

void	ft_full_sort(t_list *s)
{
	int	chpst_index;

	while (s->a_len > 3)
		ft_pb(s);
	ft_sort_three(s);
	while (s->b_len > 0)
	{
		chpst_index = cheapest_index(s);
		ft_prepare_to_pop(s, chpst_index);
		ft_pa(s);
	}
	ft_fast_rotate_a(s);
}

/* // Function to print the stacks A and B
void print_stacks(t_list *s) {
    printf("Stack A: ");
    for (int i = 0; i < s->a_len; i++) {
        printf("%d ", s->a[i]);
    }
    printf("\n");

    printf("Stack B: ");
    for (int i = 0; i < s->b_len; i++) {
        printf("%d ", s->b[i]);
    }
    printf("\n");
} */
