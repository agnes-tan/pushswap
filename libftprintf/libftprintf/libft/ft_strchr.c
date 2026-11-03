/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:17:57 by taling            #+#    #+#             */
/*   Updated: 2026/10/06 14:40:15 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     const char *str = "hello, world!";
//     char * result = ft_strchr(str, 'w');
//     if (result)
//     {
//         printf("Character found: %s\n", result);
//     }
//     else
//     {
//         printf("Character not found.\n");
//     }

// }
