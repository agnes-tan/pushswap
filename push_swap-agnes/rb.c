/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:42 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:44 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack_b, int print_flag)
{
	t_node	*current_top;
	t_node	*current_last;

	if (!stack_b || stack_b->size < 2)
		return ;
	current_top = stack_b->top;
	stack_b->top = current_top->next;
	current_last = lstlast_node(stack_b->top);
	current_last->next = current_top;
	current_top->next = NULL;
	if (print_flag)
		ps_emit(stack_b, 6);
}
