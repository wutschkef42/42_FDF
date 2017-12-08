/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 19:14:02 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/21 15:39:07 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*tmp;
	int		i;
	int		j;
	int		k;

	a = (char)c;
	tmp = (char*)s;
	i = 0;
	j = 0;
	k = 0;
	while (tmp[i])
	{
		if (a == tmp[i])
		{
			j = i;
			k++;
		}
		i++;
	}
	if (a == '\0')
		return (&tmp[(int)ft_strlen(s)]);
	if (k)
		return (&tmp[j]);
	return (0);
}
