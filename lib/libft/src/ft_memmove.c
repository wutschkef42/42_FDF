/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 00:21:08 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/21 11:08:52 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char*)dst;
	tmp2 = (unsigned char*)src;
	i = 0;
	j = len - 1;
	if (dst < src)
	{
		return (ft_memcpy(dst, src, len));
	}
	else
	{
		while (i < len)
		{
			tmp1[j] = tmp2[j];
			i++;
			j--;
		}
	}
	dst = (void*)tmp1;
	return (dst);
}
