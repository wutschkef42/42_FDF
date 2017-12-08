/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:45:52 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/28 15:10:08 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (n)
	{
		i = 0;
		tmp1 = (unsigned char*)s1;
		tmp2 = (unsigned char*)s2;
		while (tmp1[i] == tmp2[i] && i < n - 1)
			i++;
		if (tmp1[i] != tmp2[i] && n > 0)
			return (tmp1[i] - tmp2[i]);
	}
	return (0);
}
