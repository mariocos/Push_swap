#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_coordinate_moves(t_list *s, int A_moves, int B_moves)
{
		while (A_moves < 0 && B_moves < 0)
		{
			A_moves++;
			B_moves++;
			ft_rrr(s);
		}
		while (A_moves < 0)
		{
			ft_rra(s);
			A_moves++;
		}
		while (B_moves < 0)
		{
			ft_rrb(s);
			B_moves++;
		}
	reverse_rotations(s, A_moves, B_moves);
}

void	reverse_rotations(t_list *s, int A_moves, int B_moves)
{
	while (A_moves > 0 && B_moves > 0)
	{
		A_moves--;
		B_moves--;
		ft_rr(s);
	}
	while (A_moves > 0)
	{
		ft_ra(s);
		A_moves--;
	}
	while (B_moves > 0)
	{
		ft_rb(s);
		B_moves--;
	}
}

void	ft_do_moves(t_list *s, int A_moves, int B_moves)
{
	while (A_moves < 0)
	{
		ft_rra(s);
		A_moves++;
	}
	while (B_moves < 0)
	{
		ft_rrb(s);
		B_moves++;
	}
	while (A_moves > 0)
	{
		ft_ra(s);
		A_moves--;
	}
	while (B_moves > 0)
	{
		ft_rb(s);
		B_moves--;
	}
}
