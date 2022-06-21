/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:20:03 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/31 20:20:43 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_n_fill(char	**args, t_node	**a)
{
	check_digits(args);
	check_duplicates(args);
	check_maxint(args);
	*a = init_stack_a(args);
}

void	check_n_exec(t_node	**a, t_node	**b, char	*line)
{
	if (check_line(line))
	{
		write(2, "Error\n", 7);
		free(line);
		exit(1);
	}
	else
		exec_move(line, a, b);
}

void	check_n_free(t_node	**a)
{
	check_if_sorted(a);
	free_list(*a);
}
