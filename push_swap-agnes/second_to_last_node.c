/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_to_last_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:24:10 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:24:12 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*second_to_last_node(t_stack *stack)
{
	t_node	*current;
	t_node	*second_last;

	if (!stack || !stack->top || stack->size < 2)
		return (NULL);
	current = stack->top;
	second_last = NULL;
	while (current->next != NULL)
	{
		second_last = current;
		current = current->next;
	}
	return (second_last);
}
