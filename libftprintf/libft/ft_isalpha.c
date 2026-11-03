/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:13:22 by taling            #+#    #+#             */
/*   Updated: 2026/10/15 16:43:52 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <assert.h>
// int main(void)
// {
// 	// printf("%d\n", ft_isalpha('2'));
// 	assert(ft_isalpha('2') == 0);
// 	assert(ft_isalpha('-') == 1);
// 	assert(ft_isalpha('9') == 0);
// 	assert(ft_isalpha('k') == 0);
// 	return 0;
// }
