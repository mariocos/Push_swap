/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:47:07 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 13:06:09 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_invert_three(int *a)
{
	int	hold;

	hold = a[0];
	a[0] = a[2];
	a[2] = hold;
	write(1, "ra\nsa\n", 6);
}

void	ft_case_zero(int *a)
{
	int	hold;

	hold = a[1];
	a[1] = a[2];
	a[2] = hold;
	write(1, "rra\nsa\n", 7);
}

void	ft_case_one(int *a)
{
	int	hold;

	hold = a[0];
	a[0] = a[1];
	a[1] = hold;
	write(1, "sa\n", 3);
}

void	ft_case_three(int *a)
{
	int	hold;

	hold = a[2];
	a[2] = a[0];
	a[0] = a[1];
	a[1] = hold;
	write(1, "ra\n", 3);
}

void	ft_sort_three(t_list *stack)
{
	if (sort_check(stack->a, 3) == 1)
		return ;
	else if (r_sort_check(stack->a, 3) == 1)
		ft_invert_three(stack->a);
	else if (sort_check(stack->a, 2) == 1
		&& ft_index_calc(stack->a, stack->a[0], 3) == 0)
		ft_case_zero(stack->a);
	else if (sort_check(stack->a, 2) == 1
		&& ft_index_calc(stack->a, stack->a[0], 3) == 1)
		ft_rra(stack);
	else if (r_sort_check(stack->a, 2) == 1
		&& ft_index_calc(stack->a, stack->a[0], 3) == 1)
		ft_case_one(stack->a);
	else if (r_sort_check(stack->a, 2) == 1
		&& ft_index_calc(stack->a, stack->a[0], 3) == 2)
		ft_case_three(stack->a);
}
//it works its weird but works

/* #include "refactor.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(int *a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test_sort_three() {
    t_list stack;
    int combinations[6][3] = {
        {3, 2, 1},  // already sorted in reverse
        {3, 1, 2},  // Needs to be sorted
        {2, 3, 1},  // Needs to be sorted
        {2, 1, 3},  // Needs to be sorted
        {1, 3, 2},  // Needs to be sorted
        {1, 2, 3}   // already sorted
    };

    for (int i = 0; i < 6; i++) {
        printf("\nTesting combination %d: ", i + 1);
        print_stack(combinations[i], 3);

        stack.a = combinations[i];
        stack.a_len = 3;

        ft_sort_three(&stack);

        printf("Sorted stack: ");
        print_stack(stack.a, 3);
        printf("\n");
    }
}

int main() {
    test_sort_three();
    return 0;
}
 */
