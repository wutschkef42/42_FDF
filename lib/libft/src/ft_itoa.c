/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:15:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/06/13 13:51:14 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*ret;
	size_t		i;
	long		tmp;

	if (!(ret = (char*)malloc(sizeof(*ret) * ft_intlen(n))))
		return (NULL);
	if (n == -2147483648)
		tmp = 2147483648;
	else
		tmp = (n < 0) ? (long)-n : (long)n;
	i = 0;
	if (!(tmp))
		ret[i++] = '0';
	while (tmp)
	{
		ret[i++] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (n < 0)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
