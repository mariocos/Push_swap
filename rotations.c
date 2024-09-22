#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_rr(t_list *list)
{
	int	i;
	int	j;
	int	hold_A;
	int	hold_B;

	i = 0;
	j = 1;
	hold_A = list->A[0];
	hold_B = list->B[0];//can save lines with using just one hold variable
	if (list->A_len > 1)
	{
		while (j < list->A_len)
			list->A[i++] = list->A[j++];
		list->A[j - 1] = hold_A;
	}
	i = 0;
	j = 1;
	if(list->B_len > 1)
	{
		while (j < list->B_len)
			list->B[i++] = list->B[j++];
		list->B[j - 1] = hold_B;
	}
	write (1, "rr\n", 3);
}

void	ft_rrr(t_list *list)
{
	int	i;
	int	j;
	int	hold_A;
	int	hold_B;

	hold_A = list->A[list->A_len - 1];
	hold_B = list->B[list->B_len - 1];//can save lines with using just one hold variable
	i = list->A_len - 1;
	j = list->A_len - 2;
	if (list->A_len > 1)
	{
		while (i > 0)
			list->A[i--] = list->A[j--];
		list->A[0] = hold_A;
	}
	i = list->B_len - 1;
	j = list->B_len - 2;
	if(list->B_len > 1)
	{
		while (i > 0)
			list->B[i--] = list->B[j--];
		list->B[0] = hold_B;
	}
	write (1, "rrr\n", 4);
}

void	ft_fast_rotate_A(t_list *s)//might not be usde again
{
	int	min_index;
	int	A_moves;

	min_index = ft_find_min(s->A, s->A_len);
	A_moves = ft_move_calc(min_index, s->A_len);
	ft_do_moves(s, A_moves, 0);
}