/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_nearly_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:54:17 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 04:23:17 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearly_sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
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

int	if_nearly_sorted(t_node **a)
{
	t_node	*tmp;
	t_node	*comp;
	int		i;

	i = 0;
	tmp = *a;
	tmp = get_small(&tmp);
	while (i < stack_len(a) - 2)
	{
		if (!(tmp->next))
			comp = *a;
		else
			comp = tmp->next;
		if ((tmp->data) < (comp->data))
		{
			if (!(tmp->next))
				tmp = *a;
			tmp = tmp->next;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

void	sort_nearly_sorted(t_node	**a)
{
	if (if_nearly_sorted(a))
	{
		if (!left_or_right(get_index(a), a))
			ra_in(get_index(a), a);
		else if (left_or_right(get_index(a), a))
			rra_in(get_index(a), a);
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
