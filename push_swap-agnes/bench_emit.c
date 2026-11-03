/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_emit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:39:05 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 14:39:09 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*bench_op_name(int op)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	return (names[op]);
}

void	ps_emit(t_stack *stack, int op)
{
	static const char	*names[11] = {"sa\n", "sb\n", "ss\n", "pa\n",
		"pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n",
		"rrr\n"};

	if (!stack || !stack->bench || !stack->bench->silent)
		write(1, names[op], 3 + (op >= 8));
	if (stack && stack->bench)
	{
		stack->bench->count[op]++;
		stack->bench->total++;
	}
}
