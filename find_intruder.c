/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intruder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:29:23 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/01 12:36:37 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_in2(int num, int len, t_node *arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (num == arr->data)
			return (EXIT_SUCCESS);
		arr = arr->next;
		i++;
	}
	return (EXIT_FAILURE);
}

void	no_intruder(t_node **a)
{
	t_node	*tail;
	t_node	*head;
	int		l;

	head = *a;
	tail = *a;
	l = stack_len(a);
	while (l)
	{
		tail = get_last(tail);
		if (((*a)->data) > (tail->data))
			rra(a);
		l--;
	}
}

void	find_intruder(t_node *arr, int len, t_node **a, t_node **b)
{
	int	i;
	int	j;

	i = 0;
	j = stack_len(a);
	while (j > 0)
	{
		if (if_in2((*a)->data, len, arr) == 0)
			ra(a);
		else
			pb(a, b);
		j--;
	}
}
