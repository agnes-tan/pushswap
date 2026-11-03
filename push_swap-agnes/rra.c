/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:32 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:33 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, int print_flag)
{
	t_node	*current_top;
	t_node	*current_last;
	t_node	*current_second_last;

	if (!stack_a || !stack_a->top || stack_a->size < 2)
		return ;
	current_top = stack_a->top;
	current_last = lstlast_node(stack_a->top);
	current_second_last = second_to_last_node(stack_a);
	if (!current_second_last)
		return ;
	stack_a->top = current_last;
	current_last->next = current_top;
	current_second_last->next = NULL;
	if (print_flag)
		ps_emit(stack_a, 8);
}
