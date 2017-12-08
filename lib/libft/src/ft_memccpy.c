/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:39:19 by plamusse          #+#    #+#             */
/*   Updated: 2017/05/01 13:38:21 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*tmp1;
	char		*tmp2;

	i = 0;
	tmp1 = (char*)dst;
	tmp2 = (char*)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
