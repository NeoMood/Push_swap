/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:44:34 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:13:17 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inbetween_comp(t_node **a, t_node	**s, t_node	**bg)
{
	if (!((*s)->next))
		s = a;
	else
		(*s) = (*s)->next;
	if (!((*bg)->next))
		(*bg) = *a;
	else
		(*bg) = (*bg)->next;
}

int	inbetween(t_node **a, t_node **b)
{
	t_node	*s;
	t_node	*bg;
	int		i;
	int		index;

	index = 0;
	i = stack_len(a) + 1;
	s = (*a);
	bg = (*a)->next;
	while (i)
	{
		if (((s->data) < ((*b)->data)) && ((bg->data) > ((*b)->data)))
		{
			index = b_index((bg->data), a);
			break ;
		}
		inbetween_comp(a, &s, &bg);
		i--;
	}
	return (index);
}

t_node	*go_last(t_node **a)
{
	int		i;
	t_node	*tmp;

	i = stack_len(a);
	tmp = *a;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}

void	get_index_ontop(t_node **b, int index)
{
	if (!left_or_right(index, b))
		ra_in(index, b);
	else if (left_or_right(index, b))
		rra_in(index, b);
}

void	put_back(t_node **a, t_node **b)
{
	int			i;
	int			index;
	int			indexb;
	t_bestcount	*bestcount;

	bestcount = malloc(sizeof(t_count));
	if (!bestcount)
		return ;
	index = 0;
	i = stack_len(b);
	while (i)
	{
		indexb = best_element_topush(a, b, bestcount);
		execute(a, b, bestcount);
		pa(b, a);
		i--;
	}
	free(bestcount);
}
