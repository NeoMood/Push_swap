/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:22:51 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/31 19:24:32 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index1(t_node **a, t_node **b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *b;
	while ((*a)->data != tmp->data)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	execute2(t_node **a, t_node **b, t_bestcount	*bestcount)
{
	while (bestcount->rb)
	{
		rb(b);
		bestcount->rb--;
	}
	while (bestcount->rra)
	{
		rra(a);
		bestcount->rra--;
	}
	while (bestcount->rrb)
	{
		rrb(b);
		bestcount->rrb--;
	}
}

void	execute(t_node **a, t_node **b, t_bestcount	*bestcount)
{
	while (bestcount->rr)
	{
		rr(a, b);
		bestcount->rr--;
	}
	while (bestcount->rrr)
	{
		rrr(a, b);
		bestcount->rrr--;
	}
	while (bestcount->ra)
	{
		ra(a);
		bestcount->ra--;
	}
	execute2(a, b, bestcount);
}
