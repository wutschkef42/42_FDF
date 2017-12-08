/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:10:31 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/20 12:26:36 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tmp;

	i = 0;
	size = ft_strlen(little);
	tmp = (char*)big;
	while (tmp[i] && i < len)
	{
		j = 0;
		while (tmp[i] && i < len && tmp[i] == little[j])
		{
			i++;
			j++;
		}
		if (j == size)
			return (&tmp[i - j]);
		else
			i = i - j;
		i++;
	}
	return (0);
}
