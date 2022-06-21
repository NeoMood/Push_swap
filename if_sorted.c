/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:09:34 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 04:18:21 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (!(tmp->next))
		exit(EXIT_SUCCESS);
	while ((tmp)->next)
	{
		if ((tmp->data) < (tmp->next->data))
		{
			tmp = tmp->next;
			if (!(tmp->next))
			{
				exit(EXIT_FAILURE);
			}
		}
		else
			break ;
	}
}

void	rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
	write(1, "rrr\n", 4);
}
