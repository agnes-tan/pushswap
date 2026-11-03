/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_cost_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:09 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:11 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_pos(t_stack *stack_a, int b_index)
{
	t_node	*curr;
	int		pos;
	int		min_greater;
	int		target_pos;

	if (!stack_a || !stack_a->top)
		return (0);
	curr = stack_a->top;
	pos = 0;
	min_greater = INT_MAX;
	target_pos = -1;
	while (curr)
	{
		if (curr->index > b_index && curr->index < min_greater)
		{
			min_greater = curr->index;
			target_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	if (target_pos == -1)
		target_pos = find_min_pos(stack_a);
	return (target_pos);
}

t_node	*get_node_at_pos(t_stack *stack, int pos)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (i < pos && node)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	calculate_rotations(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	get_max_rotations(int a_rot, int b_rot)
{
	if (a_rot > b_rot)
		return (a_rot);
	return (b_rot);
}

void	calc_rotation_cost(t_stack *stack_a, t_stack *stack_b,
						int b_pos, t_cost *cost)
{
	t_node	*b_node;
	int		target_pos;

	b_node = get_node_at_pos(stack_b, b_pos);
	if (!b_node)
		return ;
	target_pos = find_target_pos(stack_a, b_node->index);
	cost->target_pos = target_pos;
	cost->b_rot = calculate_rotations(b_pos, stack_b->size);
	cost->a_rot = calculate_rotations(target_pos, stack_a->size);
	if ((b_pos <= stack_b->size / 2) == (target_pos <= stack_a->size / 2))
		cost->use_combined = 1;
	else
		cost->use_combined = 0;
	if (cost->use_combined)
		cost->total = get_max_rotations(cost->a_rot, cost->b_rot);
	else
		cost->total = cost->a_rot + cost->b_rot;
}
