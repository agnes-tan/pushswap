/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:31:31 by taling            #+#    #+#             */
/*   Updated: 2026/10/08 09:40:22 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\0')
		len++;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
