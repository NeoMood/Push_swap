/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:19:02 by sgmira            #+#    #+#             */
/*   Updated: 2022/05/19 04:23:00 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digits(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '-')
				j++;
			if (tab[i][j] < '0' || tab[i][j] > '9')
			{
				write(2, "Error\n", 7);
				free_tab(tab);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_maxint(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > 2147483647)
		{
			write(2, "Error\n", 7);
			free_tab(tab);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_duplicates(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = j + 1;
		while (tab[i])
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
			{
				write(2, "Error\n", 7);
				free_tab(tab);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
