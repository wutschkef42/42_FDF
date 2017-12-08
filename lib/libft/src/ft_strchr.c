/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 18:50:20 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/18 21:58:27 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*tmp;
	size_t	i;

	a = (char)c;
	tmp = (char*)s;
	i = 0;
	while (tmp[i] && tmp[i] != a)
		i++;
	if (tmp[i] == a)
		return (&tmp[i]);
	return (0);
}
