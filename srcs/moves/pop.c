/****************************************/
/*      (\__/)                          */
/*      (o^.^)                          */
/*     z(_(")_(")_                      */
/*                                      */
/*   Mariocos: push_swap revamped       */
/****************************************/

#include "../../push_swap.h"

void	ft_pb(t_list *s)
{
	int	*new_a;
	int	*new_b;
	int	i = 0;
	int	j = 1;

	new_a = malloc(sizeof(int) * (s->a_len - 1));
	new_b = malloc(sizeof(int) * (s->b_len + 1));
	if (!new_a || !new_b)
		error_exit(s);
	while (j < s->a_len)
		new_a[i++] = s->a[j++];
	new_b[0] = s->a[0];
	i = 0;
	j = 1;
	while (i < s->b_len)
		new_b[j++] = s->b[i++];
	free(s->a);
	free(s->b);
	s->a = new_a;
	s->b = new_b;
	s->a_len--;
	s->b_len++;
	write (1, "pb\n", 3);
}

void	ft_pa(t_list *s)
{
	int	*new_a;
	int	*new_b;
	int	i = 0;
	int	j = 1;

	new_a = malloc(sizeof(int) * (s->a_len + 1));
	new_b = malloc(sizeof(int) * (s->b_len - 1));
	if (!new_a || !new_b)
		error_exit(s);
	new_a[0] = s->b[0];
	i = 0;
	j = 1;
	while (i < s->a_len)
		new_a[j++] = s->a[i++];
	i = 0;
	j = 1;
	while (j < s->b_len)
		new_b[i++] = s->b[j++];
	free(s->a);
	free(s->b);
	s->a = new_a;
	s->b = new_b;
	s->a_len++;
	s->b_len--;
	write(1, "pa\n", 3);
}
