#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*checks if index is more easily reached through rotation or reverse rotation
returns positive values for rotations and negative for reverse rotations*/
int	ft_move_calc(int index, int len)
{
	if (index < len / 2)
		return (index);
	else
		return ((len - index) * -1);
}

//returns the summ of the absolute value of a and the absolute value of b
//the name is modulus because in portuguese we call this "modulo"
int	modulus_summ(int a, int b)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	return (a + b);
}

int ft_modulus(int nb)//this could in theory have a problem due to min int being larger than max int
{	
	if (nb < 0)
		nb *= -1;
	return (nb);
}