/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:34:19 by taling            #+#    #+#             */
/*   Updated: 2026/10/01 15:04:16 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_number_length(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = ft_number_length(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n == 0)
		str[0] = '0';
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s\n", ft_itoa( -123));
// 	return (0);
// }
