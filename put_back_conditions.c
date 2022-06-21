/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_conditions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:58:59 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/15 03:56:03 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_max(t_node **a, t_node **b)
{
	t_node	*tmpa;
	t_node	*tmpb;
	int		i;

	tmpa = *a;
	tmpb = *b;
	i = 0;
	while (tmpa)
	{
		if (tmpb->data > tmpa->data)
			i++;
		tmpa = tmpa->next;
	}
	if (i == stack_len(a))
		return (1);
	else
		return (0);
}

int	if_min(t_node **a, t_node **b)
{
	t_node	*tmpa;
	t_node	*tmpb;
	int		i;

	tmpa = *a;
	tmpb = *b;
	i = 0;
	while (tmpa)
	{
		if (tmpb->data < tmpa->data)
			i++;
		tmpa = tmpa->next;
	}
	if (i == stack_len(a))
		return (1);
	else
		return (0);
}
