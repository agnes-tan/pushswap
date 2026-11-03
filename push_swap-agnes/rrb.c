/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:28 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:29 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack *stack_b, int print_flag)
{
	t_node	*current_top;
	t_node	*current_last;
	t_node	*current_second_last;

	if (!stack_b || !stack_b->top || stack_b->size < 2)
		return ;
	current_top = stack_b->top;
	current_last = lstlast_node(stack_b->top);
	current_second_last = second_to_last_node(stack_b);
	if (!current_second_last)
		return ;
	stack_b->top = current_last;
	current_last->next = current_top;
	current_second_last->next = NULL;
	if (print_flag)
		ps_emit(stack_b, 9);
}
