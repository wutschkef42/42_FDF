/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:53:54 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/20 22:43:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	i;
	size_t	j;
	char	*rev;

	if (!(rev = (char*)malloc(sizeof(*rev) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i])
		rev[i++] = s[j--];
	rev[i] = '\0';
	return (rev);
}
