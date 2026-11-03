/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:50 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:52 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
