/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:48:33 by taling            #+#    #+#             */
/*   Updated: 2026/10/15 13:23:03 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_format(char specifier, va_list ap);

/* Mandatory conversions */

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long n, char format);
int		ft_putptr(void *ptr);

#endif
