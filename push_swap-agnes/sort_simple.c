/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:46 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:23:48 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	while (a->size > 0)
	{
		pos = find_min_pos(a);
		size = a->size;
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a, 1);
		}
		else
		{
			while (pos++ < size)
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	while (b->size > 0)
		pa(a, b, 1);
}
