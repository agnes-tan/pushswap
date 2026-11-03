/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:45:48 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 14:45:51 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_complex_large(t_stack *a, t_stack *b)
{
	long	turk_cost;
	long	medium_cost;
	long	radix_cost;

	turk_cost = complex_trial_cost(a, PS_COMPLEX);
	medium_cost = complex_trial_cost(a, PS_MEDIUM);
	radix_cost = complex_radix_cost(a->size);
	if (medium_cost >= 0 && medium_cost <= radix_cost
		&& (turk_cost < 0 || medium_cost <= turk_cost))
		sort_medium(a, b);
	else if (turk_cost >= 0 && turk_cost <= radix_cost)
		sort_large_turk(a, b);
	else
		complex_radix(a, b);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, 1);
	}
	else if (a->size <= 5)
		sort_small(a, b);
	else
		sort_complex_large(a, b);
}
