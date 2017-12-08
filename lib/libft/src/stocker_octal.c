/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:11:12 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:27:44 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	indent_octal(size_t arg, t_size *sz, t_dif *df)
{
	char	buf[ULLMAX + 1];
	int		i;

	if (df->pl)
		fill_ze(sz, df->pl);
	itoa_octal(arg, buf, df->al);
	i = 0;
	while (buf[i])
		fillbuffer(buf[i++], sz);
}

size_t		arglen_oc(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 8;
	return (len);
}

void		init_df_oc(t_dif *df, size_t arg, t_fwp *fwp)
{
	int		totlen;
	int		pref;

	totlen = 0;
	if (!(pref = 0) && (fwp->fi & fl_ha))
		pref = 1;
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0 + pref;
	else if (!arg)
		df->al = 1;
	else
		df->al = arglen_oc(arg) + pref;
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

void		stock_oc(size_t arg, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_oc(&df, arg, fwp);
	if (df.wl)
	{
		if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(sz, df.wl);
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, df.wl);
		indent_octal(arg, sz, &df);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
		indent_octal(arg, sz, &df);
}
