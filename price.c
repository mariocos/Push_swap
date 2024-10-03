/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:41:02 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 15:20:28 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_largest_between(int a, int b)
{
	if (a < 0 && b < 0)
	{
		if (a < b)
			return (a * -1);
		return (b * -1);
	}
	if (b > 0 && a > 0)
	{
		if (a > b)
			return (a);
		return (b);
	}
	return (-1);
}

int	move_price(t_list *s, int b_index)
{
	int	price;
	int	a_index;
	int	a_moves;
	int	b_moves;

	price = 0;
	a_index = ft_target_index(s->a, s->a_len, s->b[b_index]);
	a_moves = ft_move_calc(a_index, s->a_len);
	b_moves = ft_move_calc(b_index, s->b_len);
	if (a_moves == 0 || b_moves == 0)
		price = a_moves + b_moves;
	if (a_moves * b_moves > 0)
		price = ft_largest_between(a_moves, b_moves);
	if (a_moves * b_moves < 0)
		price = modulus_summ(a_moves, b_moves);
	return (ft_modulus(price));
}

int	cheapest_index(t_list *s)
{
	int	i;
	int	cheapest_index;
	int	price;

	i = 0;
	cheapest_index = 0;
	price = move_price(s, 0);
	while (i < s->b_len)
	{
		if (price > move_price(s, i))
		{
			price = move_price(s, i);
			cheapest_index = i;
		}
		i++;
	}
	return (cheapest_index);
}
