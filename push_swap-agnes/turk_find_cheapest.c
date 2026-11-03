/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_find_cheapest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:22:50 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:22:52 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		pos;
	int		best_pos;
	int		min_cost;
	t_cost	current_cost;

	pos = 0;
	best_pos = 0;
	min_cost = stack_a->size + stack_b->size;
	while (pos < stack_b->size)
	{
		calc_rotation_cost(stack_a, stack_b, pos, &current_cost);
		if (current_cost.total < min_cost)
		{
			min_cost = current_cost.total;
			best_pos = pos;
		}
		pos++;
	}
	return (best_pos);
}
