/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:23:53 by taling            #+#    #+#             */
/*   Updated: 2026/10/08 16:04:06 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// #include <stdio.h>

// int main(void)
// {
//     printf("%d\n", ft_atoi("s45"));
//     printf("%d\n", ft_atoi("42"));
//     printf("%d\n", ft_atoi("+987"));
//     printf("%d\n", ft_atoi("   +0"));
//     printf("%d\n", ft_atoi("   -0"));
//     printf("%d\n", ft_atoi("   2147483647"));
//     printf("%d\n", ft_atoi("   -2147483648"));
//     return 0;
// }
