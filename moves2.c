/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:13:21 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/24 19:14:33 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rb1(t_node **b)
{
	rotate(b);
}

void	ra1(t_node **a)
{
	rotate(a);
}

void	rr1(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

void	rra1(t_node **a)
{
	r_rotate(a);
}

void	rrb1(t_node **b)
{
	r_rotate(b);
}
