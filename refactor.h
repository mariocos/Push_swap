#ifndef	REFACTOR_C
#define REFACTOR_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int	*A;
	int	A_len;
	int	*B;
	int	B_len;
}		t_list;
//main.c
void	free_all(t_list *s);
void	ft_sort_four(t_list *s);
int	main(int argc, char **argv);
//setup.c
void	Error_exit(t_list *s);
int	*ft_populate_list(int argc, char **argv, t_list *s);
int ft_check_params(int argc, char **argv);
int	check_dupes(t_list *s);
t_list	*setup(int argc, char **argv);
int	isarg(int argc, char **argv);
//libft_utils.c
int	ft_strcmp(const char *str1, const char *str2);
int	ft_atoi(const char *str, t_list *s);
int		ft_isdigit(int c);
//sort checkers
int	r_sort_check(int *array, int array_len);
int	r_rotated_check(int *array, int array_len);
int	sort_check(int *array, int array_len);
int	rotated_check(int *array, int array_len);
//location utils
int	ft_islowest(int *Array, int len, int check);
int	ft_ishighest(int *Array, int len, int check);
int	ft_bottom_index(int *array, int len);
int	ft_top_index(int *array, int len);
int	ft_find_min(int *array, int len);
//location
int	ft_simple_index_calc(int *array, int len, int target);
int	ft_hard_index_calc(int *array, int len, int target);
int	ft_target_index(int *Array, int len, int target_value);
//price utils
int	ft_move_calc(int index, int len);
int	modulus_summ(int a, int b);
int ft_modulus(int nb);
//price
int	ft_largest_between(int A, int B);
int	move_price(t_list *s, int B_index);
int	cheapest_index(t_list *s);
//coordination
void	ft_coordinate_moves(t_list *s, int A_moves, int B_moves);
void	reverse_rotations(t_list *s, int A_moves, int B_moves);
void	ft_do_moves(t_list *s, int A_moves, int B_moves);
//rotations utils
void	ft_ra(t_list *s);
void	ft_rb(t_list *s);
void	ft_rra(t_list *s);
void	ft_rrb(t_list *s);
//rotations
void	ft_rr(t_list *list);
void	ft_rrr(t_list *list);
void	ft_fast_rotate_A(t_list *s);
//full_sort
void	ft_prepare_to_pop(t_list *s, int B_index);
void	ft_sort_back(t_list *s);
void	ft_full_sort(t_list *s);
//pop
void	pop_a_help(t_list *s, int *new_A, int *new_B);
void	ft_pb(t_list *s);
void	pop_b_help(t_list *s, int *new_A, int *new_B);
void	ft_pa(t_list *s);
//sort threee
void	ft_invert_three(int *A);
void	ft_case_zero(int *A);
void	ft_case_one(int *A);
void	ft_case_three(int *A);
int	ft_index_calc(int *A, int value, int len);
void	ft_sort_three(t_list *stack);



#endif