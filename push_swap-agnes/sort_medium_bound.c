/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_bound.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:01:33 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 16:01:49 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	long	trial;
	long	limit;

	if (a->size <= 1)
		return ;
	trial = complex_trial_cost(a, PS_MEDIUM);
	limit = complex_radix_cost(a->size);
	if (trial >= 0 && trial <= limit)
		sort_medium_raw(a, b);
	else
		complex_radix(a, b);
}
