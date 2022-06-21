/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:50:40 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/18 17:51:21 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_node	**tmpa, t_node	**tmpb)
{
	t_node	*a;
	t_node	*b;

	a = *tmpa;
	b = *tmpb;
	if (!sorted(&a))
		write(1, "Stack Sorted NOW!\n", 19);
	else
		write(1, "Stack still not Sorted\n", 24);
	puts("-------stack a-------");
	if (!a)
		puts("{EMPTY}");
	while (a)
	{
		printf("{%d}\n", a->data);
		a = a->next;
	}
	puts("-------stack b-------");
	if (!b)
		puts("{EMPTY}");
	while (b)
	{
		printf("{%d}\n", b->data);
		b = b->next;
	}
}
