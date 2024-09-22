#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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


int	r_sort_check(int *array, int array_len)// checks for descending order wich is desired in the B stack
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
	if (flag > 1)//flag counts how many rotation points there are
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
