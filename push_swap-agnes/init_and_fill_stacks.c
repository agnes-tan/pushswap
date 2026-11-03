/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_fill_stacks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:47 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:48 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_and_fill_stacks(t_stack **stack_a_out, t_stack **stack_b_out,
								t_indexed_val *indexed, int token_count)
{
	int		i;
	t_node	*new_node;

	*stack_a_out = stack_init();
	*stack_b_out = stack_init();
	if (!*stack_a_out || !*stack_b_out || !indexed)
		handle_error(*stack_a_out, *stack_b_out);
	i = 0;
	while (i < token_count)
	{
		new_node = create_node(indexed[i].original_value);
		if (!new_node)
			handle_error(*stack_a_out, *stack_b_out);
		new_node->index = indexed[i].index;
		add_to_back(*stack_a_out, new_node);
		i++;
	}
}
