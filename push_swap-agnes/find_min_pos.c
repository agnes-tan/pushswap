/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:23 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:24 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_node	*curr;
	int		pos;
	int		min_pos;
	int		min_idx;

	if (!stack || !stack->top)
		return (0);
	curr = stack->top;
	pos = 0;
	min_pos = 0;
	min_idx = INT_MAX;
	while (curr)
	{
		if (curr->index < min_idx)
		{
			min_idx = curr->index;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}
