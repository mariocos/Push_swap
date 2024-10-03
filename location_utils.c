/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:35 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 12:58:07 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_islowest(int *array, int len, int check)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] < check)
			return (0);
		i++;
	}
	return (1);
}

int	ft_ishighest(int *array, int len, int check)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] > check)
			return (0);
		i++;
	}
	return (1);
}

int	ft_bottom_index(int *array, int len)
{
	int	i;
	int	hold;
	int	ret_index;

	i = 0;
	hold = array[0];
	ret_index = 0;
	if (sort_check(array, len) == 1)
		return (0);
	while (i < len)
	{
		if (hold > array[i])
		{
			hold = array[i];
			ret_index = i;
		}
		i++;
	}
	return (ret_index);
}

int	ft_top_index(int *array, int len)
{
	int	i;
	int	hold;
	int	ret_index;

	i = 0;
	hold = array[0];
	ret_index = 0;
	if (sort_check(array, len) == 1)
		return (0);
	while (i < len)
	{
		if (hold < array[i])
		{
			hold = array[i];
			ret_index = i;
		}
		i++;
	}
	return (ret_index);
}

int	ft_find_min(int *array, int len)
{
	int	i;
	int	check;
	int	ret_ind;

	i = 0;
	check = array[0];
	ret_ind = 0;
	while (i < len)
	{
		if (array[i] < check)
		{
			check = array[i];
			ret_ind = i;
		}
		i++;
	}
	return (ret_ind);
}
