/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element_cond.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:14:25 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 17:14:30 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_or_max(t_node **a, t_node **b
	, t_bestpush	bestpush, t_count	*count)
{
	get_small_up_count(a, count);
	get_in_top_count(b, bestpush.indexb, count);
}

void	both_up(t_bestpush	bestpush, t_count	*count)
{
	if (bestpush.indexa > bestpush.indexb)
	{
		count->rr += bestpush.indexb;
		count->ra += bestpush.indexa - bestpush.indexb;
	}
	else if (bestpush.indexa <= bestpush.indexb)
	{
		count->rr += bestpush.indexa;
		count->rb += bestpush.indexb - bestpush.indexa;
	}
}

void	both_down(t_node **a, t_node **b
	, t_bestpush	bestpush, t_count	*count)
{
	if ((stack_len(a) - bestpush.indexa)
		> (stack_len(b) - bestpush.indexb))
	{
		count->rrr = stack_len(b) - bestpush.indexb;
		count->rra = (stack_len(a) - bestpush.indexa)
			- (stack_len(b) - bestpush.indexb);
	}
	else if ((stack_len(a) - bestpush.indexa)
		<= (stack_len(b) - bestpush.indexb))
	{
		count->rrr = stack_len(a) - bestpush.indexa;
		count->rrb = (stack_len(b) - bestpush.indexb)
			- (stack_len(a) - bestpush.indexa);
	}
}

void	up_and_down(t_node **a, t_node **b
	, t_bestpush	bestpush, t_count	*count)
{
	if (!left_or_right(bestpush.indexa, a))
	{
		count->ra += bestpush.indexa;
		count->rrb += stack_len(b) - bestpush.indexb;
	}
	else if (!left_or_right(bestpush.indexb, b))
	{
		count->rb = bestpush.indexb;
		count->rra = stack_len(a) - bestpush.indexa;
	}	
}
