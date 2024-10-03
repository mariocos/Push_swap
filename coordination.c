/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:26:30 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 12:56:47 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_coordinate_moves(t_list *s, int a_moves, int b_moves)
{
	while (a_moves < 0 && b_moves < 0)
	{
		a_moves++;
		b_moves++;
		ft_rrr(s);
	}
	while (a_moves < 0)
	{
		ft_rra(s);
		a_moves++;
	}
	while (b_moves < 0)
	{
		ft_rrb(s);
		b_moves++;
	}
	reverse_rotations(s, a_moves, b_moves);
}

void	reverse_rotations(t_list *s, int a_moves, int b_moves)
{
	while (a_moves > 0 && b_moves > 0)
	{
		a_moves--;
		b_moves--;
		ft_rr(s);
	}
	while (a_moves > 0)
	{
		ft_ra(s);
		a_moves--;
	}
	while (b_moves > 0)
	{
		ft_rb(s);
		b_moves--;
	}
}

void	ft_do_moves(t_list *s, int a_moves, int b_moves)
{
	while (a_moves < 0)
	{
		ft_rra(s);
		a_moves++;
	}
	while (b_moves < 0)
	{
		ft_rrb(s);
		b_moves++;
	}
	while (a_moves > 0)
	{
		ft_ra(s);
		a_moves--;
	}
	while (b_moves > 0)
	{
		ft_rb(s);
		b_moves--;
	}
}
