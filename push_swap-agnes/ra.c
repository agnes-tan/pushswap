/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:52 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:53 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int print_flag)
{
	t_node	*current_top;
	t_node	*current_last;

	if (!stack_a || stack_a->size < 2)
		return ;
	current_top = stack_a->top;
	stack_a->top = current_top->next;
	current_last = lstlast_node(stack_a->top);
	current_last->next = current_top;
	current_top->next = NULL;
	if (print_flag)
		ps_emit(stack_a, 5);
}
