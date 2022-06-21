/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:44:55 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:48:12 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bestpush	init_parameters(t_node **b)
{
	t_bestpush	bestpush;

	bestpush.indexb = 0;
	bestpush.indexa = 0;
	bestpush.bestindex = 0;
	bestpush.best = INT32_MAX;
	bestpush.index = 0;
	bestpush.total = 0;
	bestpush.i = stack_len(b);
	return (bestpush);
}

void	not_min_or_max(t_node **a, t_node **b,
	t_bestpush	bestpush, t_count	*count)
{
	if (!left_or_right(bestpush.indexb, b)
		&& !left_or_right(bestpush.indexa, a))
		both_up(bestpush, count);
	else if (left_or_right(bestpush.indexb, b)
		&& left_or_right(bestpush.indexa, a))
		both_down(a, b, bestpush, count);
	else
		up_and_down(a, b, bestpush, count);
}

void	increment_indexes(t_node	**tmp, t_bestpush	*bestpush)
{
	(*tmp) = (*tmp)->next;
	bestpush->i--;
	bestpush->index++;
	bestpush->indexb++;
}

void	find_best(t_bestcount *bestcount,
	t_bestpush	*bestpush, t_count *count)
{
	if (bestpush->total < bestpush->best)
	{
		bestpush->best = bestpush->total;
		bestpush->bestindex = bestpush->index;
		get_bestcount(bestcount, count);
	}
}

void	best_elem_comp(t_count	*count, t_bestpush	*bestpush,
	t_bestcount *bestcount, t_node	**tmp)
{
	bestpush->total = add_counts(count);
	find_best(bestcount, bestpush, count);
	increment_indexes(tmp, bestpush);
}
