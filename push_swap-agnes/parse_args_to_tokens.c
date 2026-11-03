/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_to_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:11 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:12 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	total_strlen(int argc, char **argv)
{
	size_t	total_len;
	int		i;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len = total_len + ft_strlen(argv[i]);
		if (i < argc - 1)
			total_len = total_len + 1;
		i++;
	}
	total_len = total_len + 1;
	return (total_len);
}

static char	*combine_argv(int argc, char **argv)
{
	char	*combined_str;
	size_t	total_len;
	int		i;

	if (argc < 2)
		handle_error(NULL, NULL);
	total_len = total_strlen(argc, argv);
	combined_str = malloc(sizeof(char) * total_len);
	if (!combined_str)
		handle_error(NULL, NULL);
	combined_str[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strlcat(combined_str, argv[i], total_len);
		if (i < argc - 1)
			ft_strlcat(combined_str, " ", total_len);
		i++;
	}
	return (combined_str);
}

char	**parse_args_to_tokens(int argc, char **argv, int *tokens_count_out)
{
	char		*combined_arg_str;
	char		**tokens;
	int			current_token_count;

	combined_arg_str = combine_argv(argc, argv);
	if (!combined_arg_str)
		handle_error(NULL, NULL);
	tokens = ft_split(combined_arg_str, ' ');
	if (!tokens)
	{
		free(combined_arg_str);
		handle_error(NULL, NULL);
	}
	free(combined_arg_str);
	current_token_count = 0;
	while (tokens[current_token_count] != NULL)
		current_token_count++;
	if (current_token_count == 0)
	{
		ft_free_split(tokens, current_token_count);
		handle_error(NULL, NULL);
	}
	*tokens_count_out = current_token_count;
	return (tokens);
}
