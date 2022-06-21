/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:23:50 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:00:06 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_list(t_node *s)
{
	while (s)
	{
		free(s);
		s = (s)-> next;
	}
	free(s);
}

void	free_all(t_node	**a, t_node	**b, char	**args)
{
	free_list(*a);
	free_list(*b);
	free_tab(args);
	exit(EXIT_SUCCESS);
}

void	free_n_exit(char	**args)
{
	free_tab(args);
	exit(EXIT_SUCCESS);
}
