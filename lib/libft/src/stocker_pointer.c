/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:07:37 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/05 18:31:42 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		indent_pointer(void *arg, t_dif *df, t_size *sz, char c)
{
	char	buf[ULLMAX + 1];
	int		i;

	if (df->cp)
		put_hex_prfx(sz, c);
	if (df->pl)
		fill_ze(sz, df->pl);
	itoa_hexa((size_t)arg, buf, df->al, c);
	i = 0;
	while (buf[i])
		fillbuffer(buf[i++], sz);
}

size_t		arglen_pt(size_t arg)
{
	int		len;

	if (!arg)
		return (1);
	len = 0;
	while (arg && ++len)
		arg = arg / 16;
	return (len);
}

void		init_df_pt(t_dif *df, void *arg, t_fwp *fwp)
{
	int		totlen;

	df->cp = 2;
	if (!(arg) && (fwp->fi & fl_pr) && !(fwp->pr))
		df->al = 0;
	else
		df->al = arglen_pt((size_t)arg);
	if (fwp->pr > df->al)
		df->pl = fwp->pr - df->al;
	else
		df->pl = 0;
	totlen = df->al + df->pl + df->cp;
	if (fwp->wi > totlen)
		df->wl = fwp->wi - totlen;
	else
		df->wl = 0;
}

int			stock_pt(void *arg, char c, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	init_df_pt(&df, arg, fwp);
	if (df.wl)
	{
		if (!(fwp->fi & fl_pr) && (fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
		{
			if (df.cp && !(df.cp = 0))
				put_hex_prfx(sz, c);
			fill_ze(sz, df.wl);
		}
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, df.wl);
		indent_pointer(arg, &df, sz, c);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
		indent_pointer(arg, &df, sz, c);
	return (1);
}
