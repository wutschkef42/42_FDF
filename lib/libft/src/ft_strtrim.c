/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:53:00 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/28 14:42:43 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*tmp;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (ft_iswhitespace(s[start]))
			start++;
		while (ft_iswhitespace(s[end - 1]))
			end--;
		if (end < start)
			end = start;
		tmp = ft_strnew(end - start);
		if (tmp == NULL)
			return (NULL);
		return (ft_strncpy(tmp, s + start, end - start));
	}
	return (NULL);
}
