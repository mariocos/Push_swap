/****************************************/
/*      (\__/)                          */
/*      (o^.^)                          */
/*     z(_(")_(")_                      */
/*                                      */
/*   Mariocos: push_swap revamped       */
/****************************************/

#include "../../push_swap.h"

void	free_double_char(char **str)
{
	int	i = 0;

	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_exit(t_list *s, char **argv)
{
	if (s)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		free (s);
	}
	if (argv)
		free_double_char(argv);
	write (2, "Error\n", 6);
	exit(1);
}
