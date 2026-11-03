/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:30 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:32 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*left;
	t_node	*right;
	long	mistakes;
	double	pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	left = a->top;
	while (left)
	{
		right = left->next;
		while (right)
		{
			if (left->index > right->index)
				mistakes++;
			right = right->next;
		}
		left = left->next;
	}
	pairs = (double)a->size * (a->size - 1) / 2.0;
	return ((double)mistakes / pairs);
}
