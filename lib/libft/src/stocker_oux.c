/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:19:48 by plamusse          #+#    #+#             */
/*   Updated: 2017/08/31 16:17:25 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		stock_oux(size_t arg, char c, t_size *sz, t_fwp *fwp)
{
	if (c == 'o' || c == 'O')
		stock_oc(arg, sz, fwp);
	else if (c == 'u' || c == 'U')
		stock_us(arg, sz, fwp);
	else if (c == 'x' || c == 'X')
		stock_hx(arg, c, sz, fwp);
}
