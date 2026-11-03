/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:48:16 by taling            #+#    #+#             */
/*   Updated: 2026/10/15 13:47:25 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putunsigned(n / 10);
	count = count + ft_putchar((n % 10) + '0');
	return (count);
}

// #include "ft_printf.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	count;

// 	count = ft_putunsigned(0);
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_putunsigned(5);
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_putunsigned(42);
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_putunsigned(123);
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_putunsigned(4294967295U);
// 	printf("\ncount = %d\n\n", count);

// 	return (0);
// }

int	ft_puthex(unsigned long n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count = count + ft_puthex(n / 16, format);
	count = count + ft_putchar(base[n % 16]);
	return (count);
}

// #include "ft_printf.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	count;

// 	count = ft_puthex(0, 'x');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(15, 'x');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(15, 'X');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(42, 'x');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(255, 'x');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(255, 'X');
// 	printf("\ncount = %d\n\n", count);

// 	count = ft_puthex(4096, 'x');
// 	printf("\ncount = %d\n\n", count);

// 	return (0);
// }

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count = count + ft_putstr("0x");
	count = count + ft_puthex((unsigned long)ptr, 'x');
	return (count);
}
