/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:52:16 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/31 20:20:36 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb_check(t_node **b)
{
	if (stack_len(b) > 1)
		sb1(b);
}

int	stack_len(t_node **a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	exec_move(char *str, t_node **a, t_node **b)
{
	if (!ft_strcmp(str, "ra\n"))
		ra_check(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb_check(b);
	else if (!ft_strcmp(str, "rr\n"))
		rr_check(a, b);
	else if (!ft_strcmp(str, "sa\n"))
		sa_check(a);
	else if (!ft_strcmp(str, "sb\n"))
		sb_check(b);
	else if (!ft_strcmp(str, "ss\n"))
		ss_check(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		rra_check(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb_check(b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr_check(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		pa_check(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb_check(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**args;
	char	*tab;
	char	*line;

	tab = get_numbers(av);
	args = ft_split(tab, ' ');
	free(tab);
	if (ac > 1)
	{
		check_n_fill(args, &a);
		line = get_next_line(0);
		if (stack_len(&a) == 1)
			return (0);
		while (line)
		{
			check_n_exec(&a, &b, line);
			line = get_next_line(0);
		}
		check_n_free(&a);
		return (0);
	}
	else
		free_n_exit(args);
}
