/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 12:17:48 by taling            #+#    #+#             */
/*   Updated: 2026/09/28 16:42:36 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *d, size_t n)
{
	const unsigned char	*src;
	const unsigned char	*dest;
	size_t				i;

	src = (const unsigned char *)s;
	dest = (const unsigned char *)d;
	i = 0;
	while (i < n)
	{
		if (src[i] != dest[i])
		{
			return (src[i] - dest[i]);
		}
		i++;
	}
	return (0);
}
