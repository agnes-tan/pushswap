/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:42 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:43 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

static void	put_num(long value)
{
	char	digits[24];
	int		i;

	i = 0;
	if (value == 0)
		digits[i++] = '0';
	while (value > 0)
	{
		digits[i++] = '0' + value % 10;
		value /= 10;
	}
	while (i > 0)
		write(2, &digits[--i], 1);
}

static void	print_strategy(t_bench *bench)
{
	static char	*names[4] = {"simple", "medium", "complex", "adaptive"};
	static char	*classes[3] = {"O(n^2)", "O(n*sqrt(n))", "O(n log n)"};

	put_str("[bench] strategy: ");
	put_str(names[bench->selected]);
	if (bench->selected == PS_ADAPTIVE)
	{
		put_str(" -> ");
		put_str(names[bench->used]);
	}
	put_str("\n[bench] complexity: ");
	put_str(classes[bench->used]);
	put_str("\n");
}

static void	print_ops(t_bench *bench)
{
	int	i;

	put_str("[bench] operations: ");
	put_num(bench->total);
	put_str("\n");
	i = 0;
	while (i < 11)
	{
		put_str("[bench] ");
		put_str(bench_op_name(i));
		put_str(": ");
		put_num(bench->count[i]);
		put_str("\n");
		i++;
	}
}

void	bench_print(t_bench *bench)
{
	long	hundredths;

	hundredths = (long)(bench->disorder * 10000.0 + 0.5);
	put_str("[bench] disorder: ");
	put_num(hundredths / 100);
	write(2, ".", 1);
	if (hundredths % 100 < 10)
		write(2, "0", 1);
	put_num(hundredths % 100);
	put_str("%\n");
	print_strategy(bench);
	print_ops(bench);
}
