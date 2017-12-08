/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocker_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 21:42:49 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:26:29 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_df_s(t_dif *df, char *arg, t_fwp *fwp)
{
	if (arg)
		df->al = ft_strlen(arg);
	else
		df->al = 0;
	if ((fwp->fi & fl_pr) && fwp->pr < df->al)
		df->pl = fwp->pr;
	else
		df->pl = df->al;
	df->wl = fwp->wi - df->pl;
	return (df->pl);
}

void	stock_s(char *arg, t_size *sz, t_fwp *fwp)
{
	t_dif	df;
	int		i;

	if (arg == NULL && !fwp->wi && putnull(sz))
		return ;
	i = init_df_s(&df, arg, fwp);
	if (df.wl)
	{
		if ((fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(sz, df.wl);
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, df.wl);
		while (i--)
			fillbuffer(*arg++, sz);
		if (fwp->fi & fl_mi)
			fill_sp(sz, df.wl);
	}
	else
	{
		while (i--)
			fillbuffer(*arg++, sz);
	}
}

void	stock_c(unsigned char arg, t_size *sz, t_fwp *fwp)
{
	if (fwp->wi)
	{
		if ((fwp->fi & fl_ze) && !(fwp->fi & fl_mi))
			fill_ze(sz, fwp->wi - 1);
		else if (!(fwp->fi & fl_mi))
			fill_sp(sz, fwp->wi - 1);
		fillbuffer(arg, sz);
		if (fwp->fi & fl_mi)
			fill_sp(sz, fwp->wi - 1);
	}
	else
		fillbuffer(arg, sz);
}
