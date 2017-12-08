/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:07:01 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:29:59 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	indent_unsigned(size_t arg, t_size *sz, t_dif *df)
{
	char	buf[ULLMAX + 1];
	int		i;

	if (df->pl)
		fill_ze(sz, df->pl);
	itoa_unsigned(arg, buf, df->al);
	i = 0;
	while (buf[i])
		fillbuffer(buf[i++], sz);
}

size_t		arglen_us(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 10;
	return (len);
}

void		init_df_us(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;

	df->al = arglen_us(arg);
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0;
	if (fwp->pr > df->al && (totlen = fwp->pr))
		df->pl = fwp->pr - df->al;
	else
	{
		totlen = df->al;
		df->pl = 0;
	}
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void		stock_us(size_t arg, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_us(&df, arg, fwp);
	if (df.wl)
	{
		if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(sz, df.wl);
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, df.wl);
		indent_unsigned(arg, sz, &df);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
		indent_unsigned(arg, sz, &df);
}
