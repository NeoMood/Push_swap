/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:54:31 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/23 15:34:59 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc (sizeof (t_node));
	if (!node)
		return (NULL);
	node -> data = content;
	node -> next = NULL;
	return (node);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	if (lst -> next == NULL)
		return (lst);
	return (ft_lstlast(lst -> next));
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*head;

	if (lst)
	{
		head = *lst;
		head = ft_lstlast(head);
		head -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (*lst || new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
