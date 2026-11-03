/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:15 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:17 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack_b, int print_flag)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	stack_b->top = second;
	first->next = second->next;
	second->next = first;
	if (print_flag)
		ps_emit(stack_b, 1);
}
