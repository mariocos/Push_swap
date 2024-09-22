#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_islowest(int *Array, int len, int check)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (Array[i] < check)//this means check isnt the lowest int in the array
			return (0);
		i++;
	}
	return (1);
}

int	ft_ishighest(int *Array, int len, int check)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (Array[i] > check)//this means check isnt the highest int in the array
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
	if (sort_check(array, len) == 1)//if the array is sorted the top will be the first
		return (0);
	while (i < len)//if the array isnt sorted it should return the index with the highest value
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
	if (sort_check(array, len) == 1)//if the array is sorted the top will be the first
		return (0);
	while (i < len)//if the array isnt sorted it should return the index with the highest value
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
	int ret_ind;

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
