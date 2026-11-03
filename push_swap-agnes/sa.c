/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:19 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 15:21:23 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int print_flag)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	stack_a->top = second;
	first->next = second->next;
	second->next = first;
	if (print_flag)
		ps_emit(stack_a, 0);
}
