/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:56 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 12:58:32 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_simple_index_calc(int *array, int len, int target)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] > target)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_hard_index_calc(int *array, int len, int target)
{
	int	i;
	int	check;
	int	ret_ind;

	ret_ind = ft_top_index(array, len);
	check = array[ret_ind];
	i = 0;
	while (i < len)
	{
		if (array[i] > target && array[i] < check)
		{
			check = array[i];
			ret_ind = i;
		}
		i++;
	}
	return (ret_ind);
}

int	ft_target_index(int *array, int len, int target_value)
{
	if (rotated_check(array, len) == 0 && sort_check(array, len) == 0)
		return (-1);
	if (ft_ishighest(array, len, target_value) == 1)
		return (ft_bottom_index(array, len));
	if (ft_islowest(array, len, target_value) == 1)
		return (ft_bottom_index(array, len));
	if (sort_check(array, len) == 1)
		return (ft_simple_index_calc(array, len, target_value));
	if (rotated_check(array, len) == 1)
		return (ft_hard_index_calc(array, len, target_value));
	return (-1);
}
