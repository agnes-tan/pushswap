/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:36 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:37 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prepare_stacks(t_stack **a, t_stack **b,
						char **args, int argc)
{
	char			**tokens;
	t_indexed_val	*indexed;
	int				count;

	tokens = parse_args_to_tokens(argc, args, &count);
	if (!tokens)
		handle_error(NULL, NULL);
	indexed = convert_and_checkdupes(tokens, count);
	ft_free_split(tokens, count);
	if (!indexed)
		handle_error(NULL, NULL);
	init_and_fill_stacks(a, b, indexed, count);
	free(indexed);
	if (!*a || !*b)
		handle_error(*a, *b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	t_bench	bench;
	int		count;

	if (argc < 2)
		return (0);
	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		handle_error(NULL, NULL);
	count = parse_flags(argc, argv, args, &bench);
	if (count < 0 || count < 2)
		return (free(args), write(2, "Error\n", 6), 1);
	prepare_stacks(&a, &b, args, count);
	free(args);
	a->bench = &bench;
	b->bench = &bench;
	bench.disorder = compute_disorder(a);
	sort_stack(a, b, &bench);
	if (bench.enabled)
		bench_print(&bench);
	stack_free(a);
	stack_free(b);
	return (0);
}
