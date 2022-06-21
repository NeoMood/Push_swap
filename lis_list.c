/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:33:26 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/09 14:33:29 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment(t_node	**tmp)
{
	if (*tmp)
		(*tmp) = (*tmp)->next;
}

t_node	*lis(t_node **a, t_node **head, int num)
{
	t_node	*tmp;
	t_node	*lis;
	int		big;

	tmp = *a;
	big = tmp->data;
	lis = ft_lstnew(big);
	if (!(tmp->next))
		tmp = *head;
	while (1)
	{
		if (big < (tmp->data))
		{
			ft_lstadd_back(&lis, ft_lstnew(tmp->data));
			big = tmp->data;
			increment(&tmp);
		}
		else
			increment(&tmp);
		if (!tmp)
			tmp = *head;
		if ((tmp->data) == num)
			break ;
	}
	return (lis);
}

int	check_same(t_node	*list1, t_node	*list2)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		i;

	tmp1 = list1;
	tmp2 = list2;
	i = stack_len(&tmp1);
	while (i > 0)
	{
		if (tmp1->data != tmp2->data)
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		i--;
	}
	return (1);
}

int	best_len(t_node **a)
{
	t_node	*tmp;
	t_lis2	vars;
	t_node	*arr;

	tmp = *a;
	vars.len = 0;
	arr = lis(&tmp, a, tmp->data);
	while (tmp)
	{
		if (stack_len(&arr) > vars.len)
		{
			vars.len = stack_len(&arr);
		}
		free_list(arr);
		tmp = tmp->next;
		if (tmp)
		{
			arr = lis(&tmp, a, tmp->data);
		}
	}
	return (vars.len);
}

t_lis2	lis_loop(t_node **a)
{
	t_node	*tmp;
	t_lis2	vars;
	t_node	*arr;
	int		bl;

	tmp = *a;
	vars.len = 0;
	arr = lis(&tmp, a, tmp->data);
	bl = best_len(a);
	while (tmp)
	{
		if (stack_len(&arr) == bl)
		{
			vars.len = stack_len(&arr);
			vars.arr = arr;
			return (vars);
		}
		else
			free_list(arr);
		tmp = tmp->next;
		if (tmp)
			arr = lis(&tmp, a, tmp->data);
	}
	return (vars);
}
