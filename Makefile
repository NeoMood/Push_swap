# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 18:47:19 by sgmira            #+#    #+#              #
#    Updated: 2022/06/09 14:33:02 by sgmira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

INCLUDE = push_swap.h
INCLUDE_B = checker.h

SRC =	fill_utils.c			\
		find_intruder.c			\
		free_tab.c				\
		ft_check_args.c			\
		if_nearly_sorted.c		\
		if_sorted.c				\
		instructions.c			\
		instructions2.c			\
		lis_list.c				\
		main.c					\
		moves_utils.c			\
		push_swap_utils.c		\
		put_back_conditions.c	\
		put_back.c				\
		split.c					\
		print_stacks.c			\
		counting.c				\
		counting2.c				\
		best_element_topush.c	\
		algo_utils.c			\
		algo_utils2.c			\
		best_element_cond.c		\
		algo_cases.c			\
		execute.c				\
		best_element_utils.c	\

SRC_B =	checker.c				\
		checker_utils.c			\
		get_next_line.c			\
		get_next_line_utils.c	\
		moves.c					\
		moves2.c				\
		move_checks.c			\
		move_checks2.c			\
		other.c					\
		main_checks.c			\
		instructions.c			\
		moves_utils.c			\
		push_swap_utils.c		\
		free_tab.c				\
		fill_utils.c			\
		split.c					\
		ft_check_args.c			\
		
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc  $(CFLAGS) -I $(INCLUDE) -o $@ $^   

bonus: $(CHECK)

$(CHECK):$(OBJ_B)
	@gcc  $(CFLAGS) -I $(INCLUDE_B) -o $(CHECK) $^ 

clean:
	@rm -f $(OBJS) $(OBJ_B)
fclean: clean
	@rm -f $(NAME) $(CHECK)
re: fclean all