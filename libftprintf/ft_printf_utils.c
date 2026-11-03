/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:48:09 by taling            #+#    #+#             */
/*   Updated: 2026/10/15 14:01:28 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// int main(void)
// {
// 	// ft_putchar("s");
// 	write(1, "s", 1);
// 	return 0;
// }

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
// int main(void)
// {
// 	char str[] = "Hello";

// 	printf("%s\n", str);

// 	return (0);
// }

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count = count + ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count = count + ft_putnbr(nb / 10);
	count = count + ft_putchar((nb % 10) + '0');
	return (count);
}

// int main(void)
// {
// 	ft_putnbr(-123);
// 	write(1, "\n", 1);
// }

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_putnbr(123));
// 	return (0);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int	count;

// 	count = ft_putnbr(-123);

// 	printf("\ncount = %d\n", count);

// 	return (0);
// }
