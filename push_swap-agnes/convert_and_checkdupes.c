/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_checkdupes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:38 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:40 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validation_error_exit(t_indexed_val *indexed,
									char **tokens, int token_count)
{
	if (indexed)
		free(indexed);
	ft_free_split(tokens, token_count);
	handle_error(NULL, NULL);
}

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	validate_tokens(char **tokens, int token_count)
{
	int			i;
	long int	num_long;

	i = 0;
	while (i < token_count)
	{
		if (!tokens[i][0] || ft_strchr(tokens[i], ' ') ||
					ft_strchr(tokens[i], '\t'))
			validation_error_exit(NULL, tokens, token_count);
		if (!is_num(tokens[i]))
			validation_error_exit(NULL, tokens, token_count);
		num_long = ft_atol(tokens[i]);
		if (num_long > INT_MAX || num_long < INT_MIN)
			validation_error_exit(NULL, tokens, token_count);
		i++;
	}
}

static void	check_duplicates(t_indexed_val *indexed,
								char **tokens, int token_count)
{
	int	i;
	int	j;

	if (!indexed)
		validation_error_exit(NULL, tokens, token_count);
	i = 0;
	while (i < token_count)
	{
		j = i + 1;
		while (j < token_count)
		{
			if (indexed[i].original_value == indexed[j].original_value)
				validation_error_exit(indexed, tokens, token_count);
			j++;
		}
		i++;
	}
}

t_indexed_val	*convert_and_checkdupes(char **tokens, int token_count)
{
	t_indexed_val	*indexed;

	validate_tokens(tokens, token_count);
	indexed = create_indexed_array(tokens, token_count);
	check_duplicates(indexed, tokens, token_count);
	return (indexed);
}
