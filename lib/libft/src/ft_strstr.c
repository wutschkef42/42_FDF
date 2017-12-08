/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:12:01 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/27 18:04:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;
	size_t		len;

	if (!(len = ft_strlen(little)))
		return ((char*)big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i] && big[i] == little[j])
		{
			i++;
			j++;
		}
		if (j == len)
			return ((char*)big + i - j);
		else
			i = i - j;
		i++;
	}
	return (0);
}
