/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:36 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:38 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	adaptive_choice(double disorder)
{
	if (disorder < 0.2)
		return (PS_SIMPLE);
	if (disorder < 0.5)
		return (PS_MEDIUM);
	return (PS_COMPLEX);
}

void	sort_stack(t_stack *a, t_stack *b, t_bench *bench)
{
	int	strategy;

	strategy = bench->selected;
	if (strategy == PS_ADAPTIVE)
		strategy = adaptive_choice(bench->disorder);
	bench->used = strategy;
	if (is_sorted(a, b))
		return ;
	if (strategy == PS_SIMPLE)
		sort_simple(a, b);
	else if (strategy == PS_MEDIUM)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
