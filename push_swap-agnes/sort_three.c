/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:32 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:34 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	t_node	*top;

	if (!stack_a || stack_a->size < 3 || !stack_a->top || !stack_a->top->next)
		return ;
	top = stack_a->top;
	if (top->index > top->next->index && top->index > top->next->next->index)
	{
		ra(stack_a, 1);
		if (stack_a->top->index > stack_a->top->next->index)
			sa(stack_a, 1);
	}
	else if (top->index > top->next->index)
		sa(stack_a, 1);
	else if (top->next->index > top->next->next->index)
	{
		rra(stack_a, 1);
		if (stack_a->top->index > stack_a->top->next->index)
			sa(stack_a, 1);
	}
}
