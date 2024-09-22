#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_ra(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	j = 1;
	hold = s->A[0];
	while (j < s->A_len)
		s->A[i++] = s->A[j++];
	s->A[j - 1] = hold;
	write (1, "ra\n", 3);
}

void	ft_rb(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	j = 1;
	hold = s->B[0];
	while (j < s->B_len)
		s->B[i++] = s->B[j++];
	s->B[j - 1] = hold;
	write (1, "rb\n", 3);
}

void	ft_rra(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = s->A_len - 1;
	j = s->A_len - 2;
	hold = s->A[s->A_len - 1];
	while (i > 0)
		s->A[i--] = s->A[j--];
	s->A[0] = hold;
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = s->B_len - 1;
	j = s->B_len - 2;
	hold = s->B[s->B_len - 1];
	while (i > 0)
		s->B[i--] = s->B[j--];
	s->B[0] = hold;
	write (1, "rrb\n", 4);
}