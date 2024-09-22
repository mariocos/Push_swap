#include "refactor.h"
#include <unistd.h>

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
		if (*str1 != *str2)
			return (0);
	}
	if (*str1 == *str2 && *str1 == '\0')
		return (1);
	return (0);
}


int	ft_atoi(const char *nptr)
{
	int	result;
	int		signal;
	int		i;
	int		hold;

	signal = 1;
	result = 0;
	i = 0;
	if (ft_strcmp(nptr,"-2147483648") == 1)
		return (-2147483648);
	if (nptr[i] == '-')
	{
		signal = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		hold = nptr[i] - 48;
		result = (result * 10) + hold;
		i++;
	}
	return (signal * result);
}