/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_indexed_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:35 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:42:30 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(long *a, long *b)
{
	long	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(long *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	get_index(long value, long *sorted_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

t_indexed_val	*create_indexed_array(char **tokens, int size)
{
	int				i;
	long			*values;
	t_indexed_val	*indexed;

	indexed = init_arrays(tokens, size, &values);
	sort_array(values, size);
	i = 0;
	while (i < size)
	{
		indexed[i].index = get_index(indexed[i].original_value, values, size);
		i++;
	}
	free(values);
	return (indexed);
}
