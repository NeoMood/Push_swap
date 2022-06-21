/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 04:13:04 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 17:17:31 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_node **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}
