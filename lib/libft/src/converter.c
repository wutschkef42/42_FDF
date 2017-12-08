/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:12:21 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/08 13:20:21 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converter(va_list valist, t_size *sz, const char c, t_fwp *fwp)
{
	char	*p;

	if ((p = ft_strchr("dDi", c)) && conv_si(valist, sz, *p, fwp))
		return (1);
	else if ((p = ft_strchr("oOuUxX", c))
			&& conv_oux(valist, sz, *p, fwp))
		return (1);
	else if ((p = ft_strchr("sScC", c)) && conv_cs(valist, sz, *p, fwp))
		return (1);
	else if (c == 'p' && stock_pt((void*)va_arg(valist, void*), 'x', sz, fwp))
		return (1);
	else if (c == 'n' && stock_n((int*)va_arg(valist, int*), sz))
		return (1);
	else
	{
		stock_c(c, sz, fwp);
		return (1);
	}
	return (0);
}
