/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:45:45 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/03 13:00:42 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	j = 1;
	hold = s->a[0];
	while (j < s->a_len)
		s->a[i++] = s->a[j++];
	s->a[j - 1] = hold;
	write (1, "ra\n", 3);
}

void	ft_rb(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = 0;
	j = 1;
	hold = s->b[0];
	while (j < s->b_len)
		s->b[i++] = s->b[j++];
	s->b[j - 1] = hold;
	write (1, "rb\n", 3);
}

void	ft_rra(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = s->a_len - 1;
	j = s->a_len - 2;
	hold = s->a[s->a_len - 1];
	while (i > 0)
		s->a[i--] = s->a[j--];
	s->a[0] = hold;
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list *s)
{
	int	i;
	int	j;
	int	hold;

	i = s->b_len - 1;
	j = s->b_len - 2;
	hold = s->b[s->b_len - 1];
	while (i > 0)
		s->b[i--] = s->b[j--];
	s->b[0] = hold;
	write (1, "rrb\n", 4);
}
