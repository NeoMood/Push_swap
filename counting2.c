/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:17:11 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/18 19:18:53 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_in_top_count(t_node **b, int index, t_count *count)
{
	if (!left_or_right(index, b))
		count->rb += index;
	else if (left_or_right(index, b))
	{
		count->rrb += stack_len(b) - index;
	}
}

void	init_counts(t_count *count)
{
	count->ra = 0;
	count->rb = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rr = 0;
	count->rrr = 0;
}

void	get_bestcount(t_bestcount *bestcount, t_count *count)
{
	bestcount->ra = count->ra;
	bestcount->rb = count->rb;
	bestcount->rra = count->rra;
	bestcount->rrb = count->rrb;
	bestcount->rr = count->rr;
	bestcount->rrr = count->rrr;
}

int	add_counts(t_count *count)
{
	int	total;

	total = count->ra + count->rb + count->rra
		+ count->rrb + count->rr + count->rrr;
	return (total);
}
