/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:56:25 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/01 22:39:41 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   CHECKER_H
# define  CHECKER_H

# define BUFFER_SIZE 1

# include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr2(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*get_buffer(int fd, char *str);
char	*get_line(char *s);
char	*rest(char *s);
char	*get_next_line(int fd);
int		stack_len(t_node **a);
void	pb1(t_node **a, t_node **b);
void	pa1(t_node **b, t_node **a);
void	sa1(t_node **a);
void	sb1(t_node **b);
void	ss1(t_node **a, t_node **b);
void	rb1(t_node **b);
void	ra1(t_node **a);
void	rr1(t_node **a, t_node **b);
void	rra1(t_node **a);
void	rrb1(t_node **b);
void	rrr1(t_node **a, t_node **b);
int		check_line(char *line);
void	check_if_sorted(t_node **a);
void	rr_check(t_node **a, t_node **b);
void	ss_check(t_node **a, t_node **b);
void	rrr_check(t_node **a, t_node **b);
void	ra_check(t_node **a);
void	rra_check(t_node **a);
void	sa_check(t_node **a);
void	pa_check(t_node **a, t_node **b);
void	pb_check(t_node **a, t_node **b);
void	rb_check(t_node **b);
void	rrb_check(t_node **b);
void	sb_check(t_node **b);
void	check_n_fill(char	**args, t_node	**a);
void	check_n_exec(t_node	**a, t_node	**b, char	*line);
void	check_n_free(t_node	**a);
void	exec_move(char *str, t_node **a, t_node **b);

#endif