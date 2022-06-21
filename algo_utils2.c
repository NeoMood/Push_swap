/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:53:24 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 04:20:47 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_node **a)
{
	t_node	*tmp;
	t_node	*pos;
	int		i;
	int		limit;

	limit = 0;
	tmp = *a;
	pos = get_small(a);
	limit = pos->data;
	i = 0;
	while ((tmp->data) != limit)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	left_or_right(int index, t_node **a)
{
	int	half;

	half = stack_len(a) / 2;
	if (index <= half)
		return (0);
	else
		return (1);
}

int	sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (!(tmp->next))
		return (0);
	while ((tmp)->next)
	{
		if ((tmp->data) < (tmp->next->data))
		{
			tmp = tmp->next;
			if (!(tmp->next))
				return (0);
		}
		else
			break ;
	}
	return (1);
}

int	stack_len(t_node **a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*get_last(t_node *tail)
{
	while (tail->next)
	{
		tail = tail->next;
	}
	return (tail);
}
