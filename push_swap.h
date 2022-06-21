/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:39:53 by sgmira            #+#    #+#             */
/*   Updated: 2022/06/08 15:48:56 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <errno.h>
# include <string.h>

typedef struct node
{
	int			data;
	struct node	*next;
}	t_node;

typedef struct lis
{
	int	len;
	int	*arr;
}	t_lis;

typedef struct count
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}	t_count;

typedef struct bestcount
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}	t_bestcount;

typedef struct lis2
{
	int		len;
	t_node	*arr;
}	t_lis2;

typedef struct bestpush
{
	int	i;
	int	index;
	int	best;
	int	bestindex;
	int	indexa;
	int	indexb;
	int	total;
}	t_bestpush;

typedef struct getnum
{
	int		i;
	int		j;
	char	**tab;
	char	*joined;
}	t_getnum;

char		*ft_strdup(const char *s1);
int			ft_strlen(const char *str);
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			ft_isdigit(int c);
int			ft_strchr(const char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
t_node		*init_stack_a(char **av);
void		check_digits(char **tab);
void		not_digit(int nb);
void		check_duplicates(char **tab);
void		delete_node(t_node	*from);
t_node		*ft_lstnew(int content);
void		ft_lstadd_back(t_node **lst, t_node *new);
void		free_tab(char **tab);
void		ft_lstadd_front(t_node **lst, t_node *new);
void		if_sorted(t_node **a);
void		push(t_node **from, t_node **to);
void		swap(t_node **list);
void		rotate(t_node **list);
void		r_rotate(t_node **list);
void		pb(t_node **a, t_node **b);
void		pa(t_node **b, t_node **a);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		rb(t_node **b);
void		ra(t_node **a);
void		rr(t_node **a, t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);
void		put_back(t_node **a, t_node **b);
int			stack_len(t_node **a);
void		no_intruder(t_node **a);
int			sorted(t_node **a);
t_node		*get_small(t_node **a);
int			if_nearly_sorted(t_node **a);
int			get_index(t_node **a);
int			left_or_right(int index, t_node **a);
void		rra_in(int index, t_node **a);
void		ra_in(int index, t_node **a);
void		sort_nearly_sorted(t_node **a);
int			if_max(t_node **a, t_node **b);
int			if_min(t_node **a, t_node **b);
int			rra_in_count(int index, t_node **a, int count);
int			ra_in_count(int index, t_node **a, int count);
void		get_small_up_count(t_node **a, t_count *count);
int			get_b_up_count(t_node **a, t_node **b, int count);
void		get_index_ontop(t_node **b, int index);
int			best_element_topush(t_node **a, t_node **b, t_bestcount *bestcount);
t_node		*lis(t_node **a, t_node **head, int num);
t_lis2		lis_loop(t_node **a);
void		find_intruder(t_node *arr, int len, t_node **a, t_node **b);
int			if_in2(int num, int len, t_node *arr);
void		get_in_top_count(t_node **b, int index, t_count *count);
void		print_stacks(t_node **a, t_node **b);
void		check_maxint(char **tab);
void		free_list(t_node *list);
char		*get_numbers(char	**av);
t_node		*init_stack_a(char **tab);
void		push_swap_algo(t_node	*a, t_node	*b, t_lis2	lis);
void		case_of_three(t_node	**a);
void		init_counts(t_count *count);
void		get_bestcount(t_bestcount *bestcount, t_count *count);
int			b_index(int pos, t_node **a);
int			inbetween(t_node **a, t_node **b);
int			add_counts(t_count *count);
int			best_element_topush(t_node **a, t_node **b, t_bestcount *bestcount);
t_node		*get_last(t_node *tail);
void		min_or_max(t_node **a, t_node **b,
				t_bestpush	bestpush, t_count	*count);
void		both_up(t_bestpush	bestpush, t_count	*count);
void		both_down(t_node **a, t_node **b,
				t_bestpush	bestpush, t_count	*count);
void		up_and_down(t_node **a, t_node **b,
				t_bestpush	bestpush, t_count	*count);
void		case_of_three(t_node	**a);
void		case_of_five(t_node	**a, t_node **b);
void		more_than_five(t_node	**a, t_node	**b, t_lis2	lis);
t_node		*get_last2(t_node	**a);
void		free_all(t_node	**a, t_node	**b, char	**args);
void		free_n_exit(char	**args);
t_getnum	space_case(char	**av, t_getnum	getnum);
void		execute(t_node **a, t_node **b, t_bestcount	*bestcount);
void		execute2(t_node **a, t_node **b, t_bestcount	*bestcount);
int			get_index1(t_node **a, t_node **b);
void		check_if_sorted(t_node **a);
int			check_line(char *line);
void		best_elem_comp(t_count	*count, t_bestpush	*bestpush,
				t_bestcount *bestcount, t_node	**tmp);
void		find_best(t_bestcount *bestcount,
				t_bestpush	*bestpush, t_count *count);
void		increment_indexes(t_node	**tmp, t_bestpush	*bestpush);
void		not_min_or_max(t_node **a, t_node **b,
				t_bestpush	bestpush, t_count	*count);
t_bestpush	init_parameters(t_node **b);

#endif