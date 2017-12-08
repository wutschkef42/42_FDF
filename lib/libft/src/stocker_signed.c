/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamsise <plamsise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:05:59 by plamsise          #+#    #+#             */
/*   Updated: 2017/09/08 13:03:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		indent_signed(long long arg, t_size *sz, t_dif *df, t_fwp *fwp)
{
	char	buf[ULLMAX + 1];
	int		i;

	if (((fwp->fi & fl_pl) || (fwp->fi & fl_sp) || (fwp->fi & fl_ne)))
		putsign(sz, fwp);
	if (df->pl)
		fill_ze(sz, df->pl);
	if (df->wl && !(fwp->fi & fl_pr) && (fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
		fill_ze(sz, df->wl);
	itoa_deci(arg, buf, df->al);
	i = 0;
	while (buf[i])
		fillbuffer(buf[i++], sz);
}

long long		arglen_si(long long arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 10;
	return (len);
}

void			init_df_si(t_dif *df, long long arg, t_fwp *fwp)
{
	int		sign;
	int		totlen;

	df->al = arglen_si(arg);
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0;
	if (!(sign = 0) && ((arg < 0 && (fwp->fi |= fl_ne)) || (fwp->fi & fl_pl)
			|| (fwp->fi & fl_sp)))
		sign = 1;
	if (fwp->pr > df->al && (totlen = fwp->pr + sign))
		df->pl = fwp->pr - df->al;
	else
	{
		totlen = df->al + sign;
		df->pl = 0;
	}
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

void			stock_si(long long arg, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_si(&df, arg, fwp);
	if (df.wl)
	{
		if (!(fwp->fi & fl_mi) && (!(fwp->fi & fl_ze) ||
					((fwp->fi & fl_ze) && (fwp->fi & fl_pr))))
			fill_sp(sz, df.wl);
		indent_signed(arg, sz, &df, fwp);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
		indent_signed(arg, sz, &df, fwp);
}
