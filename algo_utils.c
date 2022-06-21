/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:51:55 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 03:55:59 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_in(int index, t_node **a)
{
	int	limit;

	limit = stack_len(a) - index;
	while (limit)
	{
		rra(a);
		limit--;
	}
}

int	rra_in_count(int index, t_node **a, int count)
{
	int	limit;

	limit = stack_len(a) - index;
	while (limit)
	{
		count++;
		limit--;
	}
	return (count);
}

void	ra_in(int index, t_node **a)
{
	int	limit;

	limit = index;
	while (limit)
	{
		ra(a);
		limit--;
	}
}

int	ra_in_count(int index, t_node **a, int count)
{
	int	limit;

	(void)a;
	limit = index;
	while (limit)
	{
		count++;
		limit--;
	}
	return (count);
}

t_node	*get_small(t_node **a)
{
	int		small;
	int		i;
	t_node	*tmp;
	t_node	*smallpos;

	small = 0;
	i = 0;
	tmp = *a;
	smallpos = *a;
	small = tmp->data;
	while (i < stack_len(a))
	{
		if ((tmp->data) < small)
			small = tmp->data;
		tmp = tmp->next;
		i++;
	}
	while ((smallpos->data) != small)
		smallpos = smallpos->next;
	return (smallpos);
}
