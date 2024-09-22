#include "refactor.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_invert_three(int *A)
{
	int	hold;

	hold = A[0];
	A[0] = A[2];
	A[2] = hold;
	write(1, "ra\nsa\n", 6);
}

void	ft_case_zero(int *A)
{
	int	hold;

	hold = A[1];
	A[1] = A[2];
	A[2] = hold;
	write(1, "rra\nsa\n", 7);
}

void	ft_case_one(int *A)
{
	int	hold;

	hold = A[0];
	A[0] = A[1];
	A[1] = hold;
	write(1, "sa\n", 3);
}

void	ft_case_three(int *A)
{
	int	hold;

	hold = A[2];
	A[2] = A[0];
	A[0] = A[1];
	A[1] = hold;
	write(1, "ra\n", 3);
}


void	ft_sort_three(t_list *stack)//seems to be working!
{
	if (sort_check(stack->A, 3) == 1)
		return ;
	else if (r_sort_check(stack->A, 3) == 1)
		ft_invert_three(stack->A);
	else if (sort_check(stack->A, 2) == 1 && ft_index_calc(stack->A, stack->A[0], 3) == 0)
		ft_case_zero(stack->A);
	else if (sort_check(stack->A, 2) == 1 && ft_index_calc(stack->A, stack->A[0], 3) == 1)
		ft_rra(stack);
	else if (r_sort_check(stack->A, 2) == 1 && ft_index_calc(stack->A, stack->A[0], 3) == 1)
		ft_case_one(stack->A);
	else if (r_sort_check(stack->A, 2) == 1 && ft_index_calc(stack->A, stack->A[0], 3) == 2)
		ft_case_three(stack->A);
}
//it works its weird but works

/* #include "refactor.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(int *A, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void test_sort_three() {
    t_list stack;
    int combinations[6][3] = {
        {3, 2, 1},  // Already sorted in reverse
        {3, 1, 2},  // Needs to be sorted
        {2, 3, 1},  // Needs to be sorted
        {2, 1, 3},  // Needs to be sorted
        {1, 3, 2},  // Needs to be sorted
        {1, 2, 3}   // Already sorted
    };

    for (int i = 0; i < 6; i++) {
        printf("\nTesting combination %d: ", i + 1);
        print_stack(combinations[i], 3);

        stack.A = combinations[i];
        stack.A_len = 3;

        ft_sort_three(&stack);

        printf("Sorted stack: ");
        print_stack(stack.A, 3);
        printf("\n");
    }
}

int main() {
    test_sort_three();
    return 0;
}
 */