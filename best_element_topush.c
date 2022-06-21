/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element_topush.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:27:20 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:45:30 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_element_topush(t_node **a, t_node **b, t_bestcount *bestcount)
{
	t_bestpush	bestpush;
	t_node		*tmp;
	t_count		*count;

	bestpush = init_parameters(b);
	tmp = *b;
	count = malloc(sizeof(t_count));
	if (!count)
		return (0);
	init_counts(count);
	while (bestpush.i)
	{
		init_counts(count);
		if (if_min(a, &tmp) || if_max(a, &tmp))
			min_or_max(a, b, bestpush, count);
		else
		{
			bestpush.indexa = inbetween(a, &tmp);
			not_min_or_max(a, b, bestpush, count);
		}
		best_elem_comp(count, &bestpush, bestcount, &tmp);
	}
	free(count);
	return (bestpush.bestindex);
}
