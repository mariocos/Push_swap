/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:47:12 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 13:05:05 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(int *array, int array_len)
{
	int	i;

	i = 1;
	if (array_len < 1)
		return (-1);
	if (array_len == 1)
		return (1);
	while (i < array_len)
	{
		if (array[i - 1] > array[i])
			return (0);
		i++;
	}
	return (1);
}

int	r_sort_check(int *array, int array_len)
{
	int	i;

	i = 1;
	if (array_len < 1)
		return (-1);
	if (array_len == 1)
		return (1);
	while (i < array_len)
	{
		if (array[i - 1] < array[i])
			return (0);
		i++;
	}
	return (1);
}

int	rotated_check(int *array, int array_len)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (array_len < 1)
		return (-1);
	if (array_len == 1 || sort_check(array, array_len) == 1)
		return (1);
	while (i < array_len)
	{
		if (array[i - 1] > array[i])
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	if (flag == 1 && array[0] < array[array_len - 1])
		return (0);
	return (1);
}

int	r_rotated_check(int *array, int array_len)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (array_len < 1)
		return (-1);
	if (array_len == 1 || r_sort_check(array, array_len) == 1)
		return (1);
	while (i < array_len)
	{
		if (array[i - 1] < array[i])
			flag++;
		i++;
	}
	if (flag > 1)
		return (0);
	if (flag == 1 && array[0] > array[array_len - 1])
		return (0);
	return (1);
}
