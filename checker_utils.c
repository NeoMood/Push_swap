/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:04:57 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:51:29 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*init_stack_a(char **tab)
{
	t_node	*a;
	t_node	*new;
	int		i;

	if (tab[0] == (void *)0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	a = ft_lstnew(ft_atoi(tab[0]));
	i = 1;
	while (tab[i])
	{
		new = ft_lstnew(ft_atoi(tab[i]));
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

t_getnum	space_case(char	**av, t_getnum	getnum)
{
	getnum.tab = ft_split(av[getnum.i], ' ');
	if (!*getnum.tab)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	getnum.j = 0;
	while (getnum.tab[getnum.j])
	{
		getnum.joined = ft_strjoin(getnum.joined, getnum.tab[getnum.j]);
		getnum.joined = ft_strjoin(getnum.joined, " ");
		getnum.j++;
	}
	free_tab(getnum.tab);
	return (getnum);
}

char	*get_numbers(char	**av)
{
	t_getnum	getnum;

	getnum.i = 1;
	getnum.j = 0;
	getnum.joined = malloc(1);
	if (!getnum.joined)
		return (0);
	getnum.joined[0] = '\0';
	while (av[getnum.i])
	{
		if (!*av[getnum.i])
		{
			write(2, "Error\n", 7);
			exit(EXIT_FAILURE);
		}
		if (ft_strchr(av[getnum.i], ' '))
			getnum = space_case(av, getnum);
		else
		{
			getnum.joined = ft_strjoin(getnum.joined, av[getnum.i]);
			getnum.joined = ft_strjoin(getnum.joined, " ");
		}
		getnum.i++;
	}
	return (getnum.joined);
}

int	sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (!(tmp->next))
		return (0);
	while ((tmp)->next)
	{
		if ((tmp->data) < (tmp->next->data))
		{
			tmp = tmp->next;
			if (!(tmp->next))
				return (0);
		}
		else
			break ;
	}
	return (1);
}

int	check_line(char *line)
{
	if (ft_strcmp(line, "sa\n") && ft_strcmp(line, "ra\n")
		&& ft_strcmp(line, "pa\n") && ft_strcmp(line, "rra\n")
		&& ft_strcmp(line, "sb\n") && ft_strcmp(line, "rb\n")
		&& ft_strcmp(line, "pb\n") && ft_strcmp(line, "rrb\n")
		&& ft_strcmp(line, "ss\n") && ft_strcmp(line, "rr\n")
		&& ft_strcmp(line, "rrr\n"))
		return (1);
	else
		return (0);
}
