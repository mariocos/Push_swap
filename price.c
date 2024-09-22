#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_largest_between(int A, int B)//returns the value furthest from 0s
{
	if (A < 0 && B < 0)
	{
		if (A < B)
			return (A * -1);
		return (B * -1);
	}
	if (B > 0 && A > 0)
	{
		if (A > B)
			return (A);
		return (B);
	}
	return (-1);
}


int	move_price(t_list *s, int B_index)//i want to remake this but it finds the price to pop from a random array B into A sorted
{
	int	price;
	int	A_index;
	int	A_moves;//theese variables store the amount of rotations using negative numbers
	int	B_moves;//for reverse rotations and positive for rotations

	price = 0;
	A_index = ft_target_index(s->A, s->A_len, s->B[B_index]);
	A_moves = ft_move_calc(A_index, s->A_len);
	B_moves = ft_move_calc(B_index, s->B_len);
	if (A_moves == 0 || B_moves == 0)
		price = A_moves + B_moves;
	if (A_moves * B_moves > 0)
		price = ft_largest_between(A_moves, B_moves);
	if (A_moves * B_moves < 0)
		price = modulus_summ(A_moves, B_moves);
//	printf("[Ai %d Am %d Bm %d ind %d price %d ]   ", A_index, A_moves, B_moves, B_index, ft_modulus(price));
	return (ft_modulus(price));
}

int	cheapest_index(t_list *s)//cheapest to pop from b to a
{
	int	i;
	int	cheapest_index;
	int	price;

	i = 0;
	cheapest_index = 0;
	price = move_price(s, 0);
	while (i < s->B_len)
	{
		if (price > move_price(s, i))
		{
			price = move_price(s, i);
			cheapest_index = i;
		}
		i++;
	}
	return (cheapest_index);
}
