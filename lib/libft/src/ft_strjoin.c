/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:17:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/28 14:40:12 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(tmp = (char*)malloc(sizeof(*tmp) * (len1 + len2 + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
		{
			tmp[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			tmp[i++] = s2[j++];
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
