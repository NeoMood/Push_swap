/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:45:57 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/24 19:12:03 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb1(t_node **a, t_node **b)
{
	push(a, b);
}

void	pa1(t_node **b, t_node **a)
{
	push(b, a);
}

void	sa1(t_node **a)
{
	swap(a);
}

void	sb1(t_node **b)
{
	swap(b);
}

void	ss1(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
