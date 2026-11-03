/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:48:30 by taling            #+#    #+#             */
/*   Updated: 2026/10/15 15:52:38 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 'x'));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), 'X'));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
