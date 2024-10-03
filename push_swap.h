/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:43:01 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 17:49:23 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	*a;
	int	a_len;
	int	*b;
	int	b_len;
}		t_list;
//main.c
void	free_all(t_list *s);
void	ft_sort_four(t_list *s);
int		main(int argc, char **argv);
//setup.c
void	error_exit(t_list *s);
int		*ft_populate_list(int argc, char **argv, t_list *s);
int		ft_check_params(int argc, char **argv);
int		check_dupes(t_list *s);
t_list	*setup(int argc, char **argv);
int		isarg(int argc, char **argv);
//libft_utils.c
int		ft_strcmp(const char *str1, const char *str2);
int		ft_atoi(const char *str, t_list *s);
int		ft_isdigit(int c);
//sort checkers
int		r_sort_check(int *array, int array_len);
int		r_rotated_check(int *array, int array_len);
int		sort_check(int *array, int array_len);
int		rotated_check(int *array, int array_len);
//location utils
int		ft_islowest(int *Array, int len, int check);
int		ft_ishighest(int *Array, int len, int check);
int		ft_bottom_index(int *array, int len);
int		ft_top_index(int *array, int len);
int		ft_find_min(int *array, int len);
//location
int		ft_simple_index_calc(int *array, int len, int target);
int		ft_hard_index_calc(int *array, int len, int target);
int		ft_target_index(int *Array, int len, int target_value);
//price utils
int		ft_move_calc(int index, int len);
int		modulus_summ(int a, int b);
int		ft_modulus(int nb);
//price
int		ft_largest_between(int a, int b);
int		move_price(t_list *s, int b_index);
int		cheapest_index(t_list *s);
//coordination
void	ft_coordinate_moves(t_list *s, int a_moves, int b_moves);
void	reverse_rotations(t_list *s, int a_moves, int b_moves);
void	ft_do_moves(t_list *s, int a_moves, int b_moves);
//rotations utils
void	ft_ra(t_list *s);
void	ft_rb(t_list *s);
void	ft_rra(t_list *s);
void	ft_rrb(t_list *s);
//rotations
void	ft_rr(t_list *list);
void	ft_rrr(t_list *list);
void	ft_fast_rotate_a(t_list *s);
//full_sort
void	ft_prepare_to_pop(t_list *s, int b_index);
void	ft_sort_back(t_list *s);
void	ft_full_sort(t_list *s);
//pop
void	pop_a_help(t_list *s, int *new_a, int *new_b);
void	ft_pb(t_list *s);
void	pop_b_help(t_list *s, int *new_a, int *new_b);
void	ft_pa(t_list *s);
//sort threee
void	ft_invert_three(int *a);
void	ft_case_zero(int *a);
void	ft_case_one(int *a);
void	ft_case_three(int *a);
int		ft_index_calc(int *a, int value, int len);
void	ft_sort_three(t_list *stack);
//special
t_list	*special(t_list *s, char *str);
int		countwords(char const *s, char c);
int		wordlen(char *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//special utils
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dst, const char *src, char	*ret);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
