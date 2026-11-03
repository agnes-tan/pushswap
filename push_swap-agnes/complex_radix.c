/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:39:36 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 14:39:38 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	complex_radix_cost(int size)
{
	long	cost;
	long	bit;
	int		i;

	cost = 0;
	bit = 1;
	while (bit < size)
	{
		cost += size;
		i = -1;
		while (++i < size)
			if (!(i & bit))
				cost++;
		bit *= 2;
	}
	return (cost);
}

void	complex_radix(t_stack *a, t_stack *b)
{
	long	bit;
	int		size;
	int		i;

	bit = 1;
	while (bit < a->size)
	{
		size = a->size;
		i = -1;
		while (++i < size)
		{
			if (!(a->top->index & bit))
				pb(a, b, 1);
			else
				ra(a, 1);
		}
		while (b->size)
			pa(a, b, 1);
		bit *= 2;
	}
}
