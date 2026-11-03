/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:22:45 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:29:36 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a, int rotations, int direction)
{
	while (rotations > 0)
	{
		if (direction == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		rotations--;
	}
}

void	rotate_b(t_stack *stack_b, int rotations, int direction)
{
	while (rotations > 0)
	{
		if (direction == 1)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
		rotations--;
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b,
					int rotations, int direction)
{
	while (rotations > 0)
	{
		if (direction == 1)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		rotations--;
	}
}
