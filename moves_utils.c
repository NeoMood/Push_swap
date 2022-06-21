/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:18:54 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/23 14:52:56 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **from, t_node **to)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (!from)
		return ;
	tmp = ft_lstnew((*from)->data);
	if (!*to)
		*to = tmp;
	else
		ft_lstadd_front(to, tmp);
	tmp1 = *from;
	*from = (*from)->next;
	free(tmp1);
}

void	swap(t_node	**list)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!list)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp2 = *list;
	*list = (*list)->next;
	ft_lstadd_front(list, tmp);
	ft_lstadd_front(list, tmp2);
}

void	rotate(t_node	**list)
{
	t_node	*tmp;
	t_node	*head;

	if (!list || !*list)
		return ;
	head = *list;
	tmp = ft_lstnew(head->data);
	*list = (*list)->next;
	ft_lstadd_back(list, tmp);
	tmp -> next = NULL;
	free(head);
}

// void	rotate(t_node	**list)
// {
// 	t_node	*tmp;

// 	if (!list)
// 		return ;
// 	tmp = ft_lstnew((*list)->data);
// 	*list = (*list)->next;
// 	ft_lstadd_back(list, tmp);
// 	tmp -> next = NULL;
// }

void	r_rotate(t_node	**list)
{
	t_node	*tmp;
	t_node	*head;
	t_node	*tail;

	if (!list)
		return ;
	head = *list;
	while (head->next)
		head = head->next;
	tail = head;
	tmp = ft_lstnew(tail -> data);
	ft_lstadd_front(list, tmp);
	head = *list;
	while (head ->next != tail)
		head = head ->next;
	head ->next = NULL;
	free(tail);
}
