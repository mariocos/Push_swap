/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:31:49 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 18:00:49 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str, t_list *s)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		nbr *= -1;
	if (nbr > 2147483647 || nbr < -2147483648)
		error_exit(s);
	return (nbr);
}

int	isarg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
