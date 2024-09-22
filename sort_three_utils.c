#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_index_calc(int *A, int value, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (value > A[i])
			count++;
		i++;
	}
	return (count);
}