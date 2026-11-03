/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taling <taling@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:26:06 by taling            #+#    #+#             */
/*   Updated: 2026/10/29 13:26:10 by taling           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **result, int i)
{
	if (!result)
		return ;
	while (i--)
		free(result[i]);
	free(result);
}
