#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_move_calc(int index, int len)//returns negative numbers if its faster to reverse rotate
{//and positive if its faster to rotate
	if (index < len / 2)
		return (index);
	else
		return ((len - index) * -1);
}

int	modulus_summ(int a, int b)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	return (a + b);
}

int ft_modulus(int nb)//this could in theory have a problem due to min int being larger than max int
{//i dont think we will ever have a stack that large if it happens well fuck
	if (nb < 0)
		nb *= -1;
	return (nb);
}