/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:43 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:45 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_indexed_val	*init_arrays(char **tokens, int size, long **values_out)
{
	t_indexed_val	*indexed;
	long			*values;
	int				i;

	indexed = malloc(sizeof(t_indexed_val) * size);
	if (!indexed)
		handle_error(NULL, NULL);
	values = malloc(sizeof(long) * size);
	if (!values)
	{
		free(indexed);
		handle_error(NULL, NULL);
	}
	i = 0;
	while (i < size)
	{
		indexed[i].original_value = ft_atol(tokens[i]);
		values[i] = indexed[i].original_value;
		i++;
	}
	*values_out = values;
	return (indexed);
}
