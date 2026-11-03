/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:25:07 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:25:09 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	flag_strategy(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (PS_SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (PS_MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (PS_COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (PS_ADAPTIVE);
	return (-1);
}

static int	process_flag(char *arg, t_bench *bench, int *seen)
{
	int	flag;

	flag = flag_strategy(arg);
	if (flag >= 0)
	{
		if (*seen)
			return (-1);
		*seen = 1;
		bench->selected = flag;
		return (0);
	}
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		bench->enabled = 1;
		return (0);
	}
	return (1);
}

int	parse_flags(int argc, char **argv, char **args, t_bench *bench)
{
	int	i;
	int	n;
	int	seen;
	int	flag;

	ft_bzero(bench, sizeof(*bench));
	bench->selected = PS_ADAPTIVE;
	args[0] = argv[0];
	i = 0;
	n = 1;
	seen = 0;
	while (++i < argc)
	{
		flag = process_flag(argv[i], bench, &seen);
		if (flag < 0 || (flag > 0 && argv[i][0] == '\0'))
			return (-1);
		if (flag > 0)
			args[n++] = argv[i];
	}
	args[n] = NULL;
	return (n);
}
