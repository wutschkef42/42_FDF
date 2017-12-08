/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:26:12 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/08 14:27:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(va_list valist, const char *format, t_size *sz)
{
	char		*p;
	int			i;
	t_fwp		fwp;

	init_fwp(&fwp);
	i = 1;
	while (format[i] && (p = ft_strchr("#0-+ ", format[i])) && ++i)
		iflags(p, &fwp);
	while (format[i] && ft_isdigit(format[i]))
		fwp.wi = fwp.wi * 10 + (format[i++] - '0');
	if (format[i] && format[i] == '.' && (fwp.fi |= fl_pr) && ++i)
	{
		while (format[i] && ft_isdigit(format[i]))
			fwp.pr = fwp.pr * 10 + (format[i++] - '0');
	}
	while (format[i] && (p = ft_strchr("hljz", format[i])) && ++i)
		cflag(p, &fwp, format + i);
	if (format[i] && converter(valist, sz, format[i], &fwp) && ++i)
		;
	return (i);
}
