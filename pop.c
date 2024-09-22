#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	pop_a_help(t_list *s, int *new_A, int *new_B)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < s->A_len)
		new_A[i++] = s->A[j++];
	new_B[0] = s->A[0];
	i = 0;
	j = 1;
	while (i < s->B_len)
		new_B[j++] = s->B[i++];
	free(s->A);
	free(s->B);
	s->A = new_A;
	s->B = new_B;
	s->A_len--;
	s->B_len++;
}
void	ft_pa(t_list *s)
{
	int	*new_A;
	int	*new_B;

	new_A = malloc(sizeof(int) * (s->A_len - 1));
	new_B = malloc(sizeof(int) * (s->B_len + 1));
	if (!new_A || !new_B)
		return (Error_exit(s));
	pop_a_help(s, new_A, new_B);
	write (1, "pb\n", 3);
}

void	pop_b_help(t_list *s, int *new_A, int *new_B)
{
	int	i;
	int	j;

	new_A[0] = s->B[0];
	i = 0;
	j = 1;
	while (i < s->A_len)
		new_A[j++] = s->A[i++];
	i = 0;
	j = 1;
	while (j < s->B_len)
		new_B[i++] = s->B[j++];
	free(s->A);
	free(s->B);
	s->A = new_A;
	s->B = new_B;
	s->A_len++;
	s->B_len--;
}

void	ft_pb(t_list *s)
{
	int	*new_A;
	int	*new_B;

	new_A = malloc(sizeof(int) * (s->A_len + 1));
	new_B = malloc(sizeof(int) * (s->B_len - 1));
	if (!new_A || !new_B)
		return ;
	pop_b_help(s, new_A, new_B);
	write(1, "pa\n", 3);
}
