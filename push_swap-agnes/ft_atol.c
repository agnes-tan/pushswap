/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:17 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:18 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = sign * -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
