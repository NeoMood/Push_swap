/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:14:17 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/24 19:16:18 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr1(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
}

void	check_if_sorted(t_node **a)
{
	if (!sorted(a))
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
}
