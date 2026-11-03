/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:20 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:22 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	stack->bench = NULL;
	return (stack);
}

void	stack_free(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_to_back(t_stack *stack, t_node *new)
{
	t_node	*last_node;

	if (!stack || !new)
		return ;
	if (stack->top == NULL)
		stack->top = new;
	else
	{
		last_node = lstlast_node(stack->top);
		last_node->next = new;
	}
	new->next = NULL;
	stack->size++;
}

t_node	*lstlast_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}
