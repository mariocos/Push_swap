/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:40:45 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 12:45:30 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move_calc(int index, int len)
{
	if (index < len / 2)
		return (index);
	else
		return ((len - index) * -1);
}

int	modulus_summ(int a, int b)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	return (a + b);
}

int	ft_modulus(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}
