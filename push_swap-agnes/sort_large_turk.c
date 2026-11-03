/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:56 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:58 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_push_back(t_stack *stack_a, t_stack *stack_b)
{
	int	best_pos;

	while (stack_b->size > 0)
	{
		best_pos = find_cheapest_move(stack_a, stack_b);
		execute_rotations(stack_a, stack_b, best_pos);
		pa(stack_a, stack_b, 1);
	}
}

static void	rotate_to_min(t_stack *stack_a, int min_pos)
{
	int	size;

	size = stack_a->size;
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
}

void	sort_large_turk(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	turk_push_back(stack_a, stack_b);
	rotate_to_min(stack_a, find_min_pos(stack_a));
}
