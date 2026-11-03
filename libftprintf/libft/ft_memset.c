/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:17:55 by taling            #+#    #+#             */
/*   Updated: 2026/10/08 10:43:51 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;
	size_t			i;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
	return (s);
}
// int main(void)
// {
//     char str[50] = "Hello, World!";
//     printf("Before memset: %s\n", str);
//     ft_memset(str, '*', 5);
//     printf("After memset: %s\n", str);
//     return 0;
// }
