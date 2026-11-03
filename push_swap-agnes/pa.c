/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:15 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:16 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	t_node	*node_to_push;
	t_node	*b_new_top;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	node_to_push = stack_b->top;
	if (stack_b->size == 1)
		b_new_top = NULL;
	else
		b_new_top = node_to_push->next;
	stack_b->top = b_new_top;
	stack_b->size--;
	node_to_push->next = stack_a->top;
	stack_a->top = node_to_push;
	stack_a->size++;
	if (print_flag)
		ps_emit(stack_a, 3);
}
