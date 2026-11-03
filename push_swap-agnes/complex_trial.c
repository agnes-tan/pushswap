/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_trial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:39:25 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 15:46:14 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*duplicate_stack(t_stack *source)
{
	t_stack	*copy;
	t_node	*current;
	t_node	*node;

	copy = stack_init();
	if (!copy)
		return (NULL);
	current = source->top;
	while (current)
	{
		node = create_node(current->value);
		if (!node)
			return (stack_free(copy), NULL);
		node->index = current->index;
		add_to_back(copy, node);
		current = current->next;
	}
	return (copy);
}

long	complex_trial_cost(t_stack *a, int strategy)
{
	t_stack	*copy_a;
	t_stack	*copy_b;
	t_bench	bench;
	long	result;

	copy_a = duplicate_stack(a);
	if (!copy_a)
		return (-1);
	copy_b = stack_init();
	if (!copy_b)
		return (stack_free(copy_a), -1);
	ft_bzero(&bench, sizeof(bench));
	bench.silent = 1;
	copy_a->bench = &bench;
	copy_b->bench = &bench;
	if (strategy == PS_MEDIUM)
		sort_medium_raw(copy_a, copy_b);
	else
		sort_large_turk(copy_a, copy_b);
	result = bench.total;
	stack_free(copy_a);
	stack_free(copy_b);
	return (result);
}
