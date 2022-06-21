/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:37:41 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/18 19:17:40 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_index(int pos, t_node **a)
{
	t_node	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp && (tmp->data) != pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	get_small_up(t_node **a)
{
	int	i;

	i = get_index(a);
	if (!left_or_right(i, a))
		ra_in(i, a);
	else if (left_or_right(i, a))
		rra_in(i, a);
}

void	get_small_up_count(t_node **a, t_count *count)
{
	int	i;

	i = get_index(a);
	if (!left_or_right(i, a))
		count->ra += i;
	else if (left_or_right(i, a))
		count->rra += stack_len(a) - i;
}

void	get_b_up(t_node **a, t_node **b)
{
	int	i;

	i = inbetween(a, b);
	if (!left_or_right(i, a))
		ra_in(i, a);
	else if (left_or_right(i, a))
		rra_in(i, a);
}

int	get_b_up_count(t_node **a, t_node **b, int count)
{
	int	i;

	i = inbetween(a, b);
	if (!left_or_right(i, a))
		count += i;
	else if (left_or_right(i, a))
		count += stack_len(a) - i;
	return (count);
}
