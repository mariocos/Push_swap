/****************************************/
/*      (\__/)                          */
/*      (o^.^)                          */
/*     z(_(")_(")_                      */
/*                                      */
/*   Mariocos: push_swap revamped       */
/****************************************/

#include "../../push_swap.h"

static char	*ft_strcat(char *dst, const char *src, char	*ret)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst && dst[i] != '\0')
	{
		ret[i] = dst[i];
		i++;
	}
	while (src && src[j] != '\0')
		ret[i++] = src[j++];
	ret[i] = '\0';
	return (ret);
}

static char	*ft_strjoin(char const *s1, char const *s2)
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

char	*join_args(char **argv)
{
	char	*ret = NULL;
	char	*help = NULL;
	char	*hold = NULL;
	int		i = 0;

	while (argv[i] != NULL)
	{
		help = ft_strjoin(argv[i], " ");
		hold = ft_strjoin(ret, help);
		free(ret);
		free(help);
		ret = hold;
		i++;
	}
	return (ret);
}