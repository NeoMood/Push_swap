/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checks2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:13:07 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 18:14:08 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_check(t_node **a)
{
	if (stack_len(a) > 1)
		sa1(a);
}

void	pa_check(t_node **a, t_node **b)
{
	if (stack_len(b) > 0)
		pa1(b, a);
}

void	pb_check(t_node **a, t_node **b)
{
	if (stack_len(a) > 0)
		pb1(a, b);
}

void	rb_check(t_node **b)
{
	if (stack_len(b) > 1)
		rb1(b);
}

void	rrb_check(t_node **b)
{
	if (stack_len(b) > 1)
		rrb1(b);
}
