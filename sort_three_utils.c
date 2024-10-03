/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:47:10 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 13:02:17 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_calc(int *a, int value, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (value > a[i])
			count++;
		i++;
	}
	return (count);
}
