/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_wcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:29:55 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:31:23 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wcharlen(wchar_t arg)
{
	if (!(arg >> 7))
		return (1);
	else if (!(arg >> 11))
		return (2);
	else if (!(arg >> 16))
		return (3);
	else
		return (4);
}

int		init_df_ws(wchar_t *arg, t_fwp *fwp, t_dif *df)
{
	int		i;

	df->al = 0;
	i = 0;
	if (fwp->pr || (fwp->fi & fl_pr))
	{
		while (arg[i] && df->al < fwp->pr)
			df->al += wcharlen(arg[i++]);
		if (df->al > fwp->pr)
			df->al -= wcharlen(arg[--i]);
	}
	else
	{
		while (arg[i])
			df->al += wcharlen(arg[i++]);
	}
	if (fwp->wi > df->al)
		df->wl = fwp->wi - df->al;
	else
		df->wl = 0;
	return (i);
}

void	stock_ws(wchar_t *arg, t_size *sz, t_fwp *fwp)
{
	int		i;
	t_dif	df;

	if (arg == NULL && !fwp->wi && putnull(sz))
		return ;
	i = init_df_ws(arg, fwp, &df);
	if (df.wl)
	{
		if ((fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(sz, df.wl);
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, df.wl);
		while (i--)
			ft_putwchar(*arg++, sz);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
	{
		while (i--)
			ft_putwchar(*arg++, sz);
	}
}

void	stock_wc(wchar_t arg, t_size *sz, t_fwp *fwp)
{
	t_dif	df;

	df.al = wcharlen(arg);
	if (fwp->wi)
	{
		df.wl = fwp->wi - df.al;
		if (fwp->fi & fl_mi)
		{
			ft_putwchar(arg, sz);
			fill_sp(sz, df.wl);
		}
		else
		{
			fill_sp(sz, df.wl);
			ft_putwchar(arg, sz);
		}
	}
	else
		ft_putwchar(arg, sz);
}
