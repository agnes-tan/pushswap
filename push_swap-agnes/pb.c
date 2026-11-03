/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:04 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:05 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b, int print_flag)
{
	t_node	*node_to_push;
	t_node	*a_new_top;

	if (!stack_a || !stack_b || stack_a->size == 0)
		return ;
	node_to_push = stack_a->top;
	if (stack_a->size == 1)
		a_new_top = NULL;
	else
		a_new_top = node_to_push->next;
	stack_a->top = a_new_top;
	stack_a->size--;
	node_to_push->next = stack_b->top;
	stack_b->top = node_to_push;
	stack_b->size++;
	if (print_flag)
		ps_emit(stack_a, 4);
}
