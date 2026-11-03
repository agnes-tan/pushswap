/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:01 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:03 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_position(t_stack *stack_a, t_node **min, int *pos)
{
	t_node	*curr;
	int		i;

	*min = stack_a->top;
	curr = stack_a->top;
	*pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->index < (*min)->index)
		{
			*min = curr;
			*pos = i;
		}
		curr = curr->next;
		i++;
	}
}

static void	rotate_to_min(t_stack *stack_a, t_node *min, int pos)
{
	while (stack_a->top != min)
	{
		if (pos <= stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int		pushed;
	t_node	*min;
	int		pos;

	pushed = 0;
	while (pushed < 2 && stack_a->size > 3)
	{
		find_min_position(stack_a, &min, &pos);
		rotate_to_min(stack_a, min, pos);
		pb(stack_a, stack_b, 1);
		pushed++;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, 1);
}
