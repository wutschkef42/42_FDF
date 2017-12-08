/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 20:09:17 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/10 17:02:31 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillbuffer(unsigned char c, t_size *sz)
{
	if (sz->no >= BS && (sz->op += sz->no) && !(sz->no = 0))
		write(1, sz->buf, BS);
	sz->buf[sz->no++] = c;
}

void	init_size(t_size *sz)
{
	sz->no = 0;
	sz->op = 0;
	sz->er = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		valist;
	t_size		sz;
	static int	error = 0;

	va_start(valist, format);
	init_size(&sz);
	while (*format)
	{
		if (*format != '%')
			fillbuffer(*format++, &sz);
		else
			format += parser(valist, format, &sz);
	}
	va_end(valist);
	if (write(1, sz.buf, sz.no))
		sz.op += sz.no;
	if ((sz.er == -1 || error == -1) && (error = -1))
		return (error);
	return (sz.op);
}
