#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//this file used to be used to find the location in a r sorted array but this version does
//the exact same but into a sorted array like 1 2 3 4 5

//changed to sorted
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
	return (-1);//should never reach here it means theres a problem
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

//returns index to be brought up to pop into sorted stack
int	ft_target_index(int *Array, int len, int target_value)
{
	if (rotated_check(Array, len) == 0 && sort_check(Array, len) == 0)
		return (-1);
	if (ft_ishighest(Array, len, target_value) == 1)
		return (ft_bottom_index(Array, len));//since its now sorted its bottom index
	if (ft_islowest(Array, len, target_value) == 1)
		return (ft_bottom_index(Array, len));
	if (sort_check(Array, len) == 1)
		return (ft_simple_index_calc(Array, len, target_value));
	if (rotated_check(Array, len) == 1)
		return (ft_hard_index_calc(Array, len, target_value));
	return (-1);
}
