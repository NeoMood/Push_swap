/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:08:12 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 18:13:24 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rr_check(t_node **a, t_node **b)
{
	if (stack_len(a) > 1 && stack_len(b) > 1)
		rr1(a, b);
	else if (stack_len(a) > 1 && stack_len(b) < 1)
		ra1(a);
	else if (stack_len(a) < 1 && stack_len(b) > 1)
		rb1(b);
}

void	ss_check(t_node **a, t_node **b)
{
	if (stack_len(a) > 1 && stack_len(b) > 1)
		ss1(a, b);
	else if (stack_len(a) > 1 && stack_len(b) < 1)
		sa1(a);
	else if (stack_len(a) < 1 && stack_len(b) > 1)
		sb1(b);
}

void	rrr_check(t_node **a, t_node **b)
{
	if (stack_len(a) > 1 && stack_len(b) > 1)
		rrr1(a, b);
	else if (stack_len(a) > 1 && stack_len(b) < 1)
		rra1(a);
	else if (stack_len(a) < 1 && stack_len(b) > 1)
		rrb1(b);
}

void	ra_check(t_node **a)
{
	if (stack_len(a) > 1)
		ra1(a);
}

void	rra_check(t_node **a)
{
	if (stack_len(a) > 1)
		rra1(a);
}
