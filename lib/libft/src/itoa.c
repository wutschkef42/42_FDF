/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:13:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:24:54 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_unsigned(unsigned long long arg, char *buf, int len)
{
	buf[len] = 0;
	while (len)
	{
		buf[--len] = ft_abs(arg % 10) + '0';
		arg /= 10;
	}
}

void		itoa_deci(long long arg, char *buf, int len)
{
	buf[len] = 0;
	while (len)
	{
		buf[--len] = ft_abs(arg % 10) + '0';
		arg /= 10;
	}
}

void		itoa_octal(size_t arg, char *buf, int len)
{
	buf[len] = 0;
	while (len)
	{
		buf[--len] = arg % 8 + '0';
		arg /= 8;
	}
}

int			get_hex(int nb, char c)
{
	int		ret;

	if (c == 'x')
		ret = 49;
	else
		ret = 17;
	if (nb == 10)
		return (ret += 0);
	else if (nb == 11)
		return (ret += 1);
	else if (nb == 12)
		return (ret += 2);
	else if (nb == 13)
		return (ret += 3);
	else if (nb == 14)
		return (ret += 4);
	else if (nb == 15)
		return (ret += 5);
	else
		return (nb);
}

void		itoa_hexa(size_t arg, char *buf, int len, char c)
{
	buf[len] = 0;
	while (len)
	{
		buf[--len] = get_hex((arg % 16), c) + '0';
		arg /= 16;
	}
}
