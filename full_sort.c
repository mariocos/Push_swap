#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//this file is for the algorithm used on stacks that are atleast 5 elements big

void	ft_prepare_to_pop(t_list *s, int B_index)
{
	int	A_moves;
	int	B_moves;
	B_moves = ft_move_calc(B_index, s->B_len);
	A_moves = ft_move_calc(ft_target_index(s->A, s->A_len, s->B[B_index]), s->A_len);
	if (A_moves * B_moves > 0)
		ft_coordinate_moves(s, A_moves, B_moves);
	else
		ft_do_moves(s, A_moves, B_moves);
}

void	ft_sort_back(t_list *s)
{
	int	rots;

	rots = 3;
	while (s->B_len > 0)
	{
		while (rots > 0 && s->B[0] < s->A[s->A_len - 1])
		{
			ft_rra(s);
			rots--;
		}
		ft_pa(s);
	}
	if (rots > 0)
	{
		ft_rra(s);
		rots--;
	}
}

void	ft_full_sort(t_list *s)
{
	int	chpst_index;

	while (s->A_len > 3)
		ft_pb(s);
	ft_sort_three(s);
	while (s->B_len > 0)
	{
		chpst_index = cheapest_index(s);
		ft_prepare_to_pop(s, chpst_index);
		ft_pa(s);
	}
	ft_fast_rotate_A(s);
}

/* // Function to print the stacks A and B
void print_stacks(t_list *s) {
    printf("Stack A: ");
    for (int i = 0; i < s->A_len; i++) {
        printf("%d ", s->A[i]);
    }
    printf("\n");

    printf("Stack B: ");
    for (int i = 0; i < s->B_len; i++) {
        printf("%d ", s->B[i]);
    }
    printf("\n");
} */