/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:39:05 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 16:25:25 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_stack_a(char **tab)
{
	t_node	*a;
	t_node	*new;
	int		i;

	if (tab[0] == (void *)0)
		exit(EXIT_FAILURE);
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

char	*get_numbers(char	**av)
{
	t_getnum	getnum;

	getnum.i = 1;
	getnum.j = 0;
	getnum.joined = malloc(1);
	getnum.joined[0] = '\0';
	while (av[getnum.i])
	{
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

void	check_n_init(char	**args, t_node	**a)
{
	check_digits(args);
	check_duplicates(args);
	check_maxint(args);
	*a = init_stack_a(args);
}

void	algorithm(t_node	**a, t_node	**b, t_lis2	lis)
{
	if (stack_len(a) == 2)
		sort_nearly_sorted(a);
	else if (stack_len(a) == 3)
		case_of_three(a);
	else if (stack_len(a) == 5)
		case_of_five(a, b);
	else
		more_than_five(a, b, lis);
}

int	main(int ac, char	**av)
{
	char	**args;
	t_node	*a;
	t_node	*b;
	char	*tab;
	t_lis2	lis;

	lis.arr = NULL;
	tab = get_numbers(av);
	args = ft_split(tab, ' ');
	free(tab);
	if (ac > 1)
	{
		check_n_init(args, &a);
		if (sorted(&a))
			algorithm(&a, &b, lis);
		free_all(&a, &b, args);
	}
	else
		free_n_exit(args);
}
