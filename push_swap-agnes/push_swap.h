/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:40:23 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 15:49:03 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libftprintf/libft/libft.h"

# define PS_SIMPLE 0
# define PS_MEDIUM 1
# define PS_COMPLEX 2
# define PS_ADAPTIVE 3

typedef struct s_indexed_val
{
	int			original_value;
	int			index;
}	t_indexed_val;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	long		count[11];
	long		total;
	double		disorder;
	int			selected;
	int			used;
	int			enabled;
	int			silent;
}	t_bench;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	t_bench	*bench;
}	t_stack;

typedef struct s_cost
{
	int	a_rot;
	int	b_rot;
	int	total;
	int	use_combined;
	int	target_pos;
}	t_cost;

/* Input handling */
char			**parse_args_to_tokens(int argc, char **argv, int *count);
t_indexed_val	*convert_and_checkdupes(char **tokens, int count);
t_indexed_val	*init_arrays(char **tokens, int size, long **values);
t_indexed_val	*create_indexed_array(char **tokens, int size);
void			init_and_fill_stacks(t_stack **a, t_stack **b,
					t_indexed_val *indexed, int count);
void			handle_error(t_stack *a, t_stack *b);
void			ft_free_split(char **result, int size);
long int		ft_atol(const char *str);
int				parse_flags(int argc, char **argv, char **args, t_bench *bench);

/* Operations */
void			sa(t_stack *a, int print_flag);
void			sb(t_stack *b, int print_flag);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b, int print_flag);
void			pb(t_stack *a, t_stack *b, int print_flag);
void			ra(t_stack *a, int print_flag);
void			rb(t_stack *b, int print_flag);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a, int print_flag);
void			rrb(t_stack *b, int print_flag);
void			rrr(t_stack *a, t_stack *b);
void			ps_emit(t_stack *stack, int op);
char			*bench_op_name(int op);

/* Sorting */
void			sort_three(t_stack *a);
void			sort_five(t_stack *a, t_stack *b);
void			sort_small(t_stack *a, t_stack *b);
void			sort_large_turk(t_stack *a, t_stack *b);
void			sort_simple(t_stack *a, t_stack *b);
void			sort_medium(t_stack *a, t_stack *b);
void			sort_medium_raw(t_stack *a, t_stack *b);
void			sort_complex(t_stack *a, t_stack *b);
void			complex_radix(t_stack *a, t_stack *b);
long			complex_radix_cost(int size);
long			complex_trial_cost(t_stack *a, int strategy);
void			sort_stack(t_stack *a, t_stack *b, t_bench *bench);
int				is_sorted(t_stack *a, t_stack *b);
double			compute_disorder(t_stack *a);
void			bench_print(t_bench *bench);

/* Stack utilities */
t_stack			*stack_init(void);
t_node			*create_node(int value);
t_node			*lstlast_node(t_node *node);
void			add_to_back(t_stack *stack, t_node *new_node);
void			stack_free(t_stack *stack);
t_node			*second_to_last_node(t_stack *stack);
int				find_min_pos(t_stack *stack);
void			rotate_a(t_stack *a, int rotations, int direction);
void			rotate_b(t_stack *b, int rotations, int direction);
void			rotate_both(t_stack *a, t_stack *b, int rotations, int dir);

/* Original Turk helpers */
int				find_target_pos(t_stack *a, int b_index);
void			calc_rotation_cost(t_stack *a, t_stack *b,
					int pos, t_cost *cost);
int				find_cheapest_move(t_stack *a, t_stack *b);
void			execute_rotations(t_stack *a, t_stack *b, int pos);
void			turk_push_back(t_stack *a, t_stack *b);
t_node			*get_node_at_pos(t_stack *stack, int pos);
int				calculate_rotations(int pos, int size);
int				get_max_rotations(int a_rot, int b_rot);

#endif
