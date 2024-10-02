#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	free_all(t_list *s)
{
	if (s->A)
		free(s->A);
	if (s->B)
		free(s->B);
	free(s);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list *s;

	s = setup(argc, argv);
	if (!s)
		Error_exit(s);
	if (sort_check(s->A, s->A_len) == 1)//theese two might leak but ill add the free function in a bit
		free_all(s);
	else if (s->A_len >= 4)
		ft_full_sort(s);
	else if (s->A_len == 3)
		ft_sort_three(s);
	else if (s->A_len == 2 && sort_check(s->A, s->A_len) == 0)
		write(1, "sa\n", 3);
	free_all(s);
	return (1);
}