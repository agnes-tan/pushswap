# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taling <taling@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/29 14:40:04 by taling            #+#    #+#              #
#    Updated: 2026/10/29 14:40:07 by taling           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = libftprintf
LIBFT = $(LIBDIR)/libftprintf.a
INCLUDES = -I$(LIBDIR)/libft -I$(LIBDIR)/ft_printf

SRC = main.c parse_flags.c disorder.c bench.c bench_emit.c \
      parse_args_to_tokens.c convert_and_checkdupes.c init_arrays.c \
      create_indexed_array.c ft_free_split.c ft_atol.c \
      stack_utils.c init_and_fill_stacks.c second_to_last_node.c \
      find_min_pos.c is_sorted.c handle_error.c \
      sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c \
      sort_stack.c sort_simple.c sort_medium.c sort_medium_bound.c \
      sort_complex.c complex_radix.c complex_trial.c \
      sort_three.c sort_five.c sort_small.c \
      sort_large_turk.c turk_cost_calc.c turk_find_cheapest.c turk_rotations.c turk_execute.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
