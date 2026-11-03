/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:22:59 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:03 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_rotations(int a_rot, int b_rot)
{
	if (a_rot < b_rot)
		return (a_rot);
	return (b_rot);
}

static void	execute_combined_rotations(t_stack *stack_a, t_stack *stack_b,
									t_cost *cost, int direction)
{
	int	combined_rots;
	int	remaining_a;
	int	remaining_b;

	combined_rots = get_min_rotations(cost->a_rot, cost->b_rot);
	remaining_a = cost->a_rot - combined_rots;
	remaining_b = cost->b_rot - combined_rots;
	rotate_both(stack_a, stack_b, combined_rots, direction);
	rotate_a(stack_a, remaining_a, direction);
	rotate_b(stack_b, remaining_b, direction);
}

static int	get_direction(int pos, int size)
{
	if (pos <= size / 2)
		return (1);
	return (-1);
}

void	execute_rotations(t_stack *stack_a, t_stack *stack_b, int best_pos)
{
	t_cost	cost;
	int		b_direction;
	int		a_direction;

	calc_rotation_cost(stack_a, stack_b, best_pos, &cost);
	b_direction = get_direction(best_pos, stack_b->size);
	a_direction = get_direction(cost.target_pos, stack_a->size);
	if (cost.use_combined)
		execute_combined_rotations(stack_a, stack_b, &cost, b_direction);
	else
	{
		rotate_a(stack_a, cost.a_rot, a_direction);
		rotate_b(stack_b, cost.b_rot, b_direction);
	}
}
