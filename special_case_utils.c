/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:44:25 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 17:48:45 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		str_len;
	char	*dest;
	int		i;

	i = 0;
	str_len = ft_strlen(s) + 1;
	dest = malloc(sizeof(char) * str_len);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (i + 1 < size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (count);
}

char	*ft_strcat(char *dst, const char *src, char	*ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		ret[i] = dst[i];
		i++;
	}
	while (src[j] != '\0')
		ret[i++] = src[j++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen((const char *)s1);
	s2_len = ft_strlen((const char *)s2);
	ret = malloc(s1_len + s2_len + 1);
	if (ret == NULL)
		return (NULL);
	ret[0] = '\0';
	ft_strcat((char *)s1, (char *)s2, ret);
	return (ret);
}
