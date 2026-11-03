/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:26:01 by taling            #+#    #+#             */
/*   Updated: 2026/09/28 16:27:07 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('A'));
// 	printf("%d\n", ft_isalnum('1'));
// 	printf("%d\n", ft_isalnum('@'));
// 	return (0);
// }
