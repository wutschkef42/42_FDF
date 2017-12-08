/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:26:38 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/14 15:11:03 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	unsigned char	*tmp;
	size_t			i;

	a = (unsigned char)c;
	tmp = b;
	i = 0;
	while (i < len)
	{
		tmp[i] = a;
		i++;
	}
	b = tmp;
	return (b);
}
