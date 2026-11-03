/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:16:43 by taling            #+#    #+#             */
/*   Updated: 2026/10/08 10:09:54 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
// #include <stdio.h>

// int main(void)
// {
//     char str[50] = "Hello, World!";
//     printf("Before bzero: %s\n", str);
//     ft_bzero(str, 5);
//     printf("After bzero: %s\n", str);
//     return 0;
// }
