/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:23:51 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 16:04:03 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	integer_sqrt(int n)
{
	int	r;

	r = 1;
	while (r <= n / r)
		r++;
	return (r - 1);
}

static void	push_chunks(t_stack *a, t_stack *b, int range)
{
	while (a->size > 0)
	{
		if (a->top->index <= b->size)
		{
			pb(a, b, 1);
			rb(b, 1);
		}
		else if (a->top->index <= b->size + range)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
}

static int	find_max_position(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		pos;

	cur = b->top;
	max = -1;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

static void	drain_chunks(t_stack *a, t_stack *b)
{
	int	pos;
	int	size;

	while (b->size > 0)
	{
		pos = find_max_position(b);
		size = b->size;
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				rb(b, 1);
		}
		else
		{
			while (pos++ < size)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

void	sort_medium_raw(t_stack *a, t_stack *b)
{
	int	range;

	range = integer_sqrt(a->size) * 7 / 5;
	if (range < 1)
		range = 1;
	push_chunks(a, b, range);
	drain_chunks(a, b);
}
