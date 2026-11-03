/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:16:02 by taling            #+#    #+#             */
/*   Updated: 2026/10/08 12:22:50 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;
	size_t	total;

	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	total = n * size;
	result = malloc(total);
	if (!result)
		return (NULL);
	ft_bzero (result, total);
	return (result);
}
