/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:35:19 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/04 20:58:36 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last2(t_node	**a)
{
	t_node	*tmp;
	int		i;

	tmp = *a;
	i = stack_len(a) - 1;
	while (i)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp);
}

void	case_of_three(t_node	**a)
{
	t_node	*head;
	t_node	*next;
	t_node	*last;

	head = *a;
	next = (*a)->next;
	last = get_last2(a);
	if ((head->data) > (next->data) && (head->data) > (last->data)
		&& (next->data) < (head->data) && (next->data) < (last->data))
		ra(a);
	else if ((next->data) < (head->data) && (next->data) < (last->data))
		sa(a);
	else if ((head->data) > (next->data) && (head->data) > (last->data)
		&& (next->data) < (head->data) && (next->data) > (last->data))
	{
		sa(a);
		rra(a);
	}
	else if ((last->data) < (next->data) && (last->data) > (head->data))
	{
		sa(a);
		ra(a);
	}
	else if ((last->data) < (head->data) && (last->data) < (next->data))
		rra(a);
}

void	case_of_five(t_node	**a, t_node **b)
{
	pb(a, b);
	pb(a, b);
	case_of_three(a);
	put_back(a, b);
	sort_nearly_sorted(a);
}

void	more_than_five(t_node	**a, t_node	**b, t_lis2	lis)
{	
	lis = lis_loop(a);
	find_intruder(lis.arr, lis.len, a, b);
	free_list(lis.arr);
	put_back(a, b);
	sort_nearly_sorted(a);
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
