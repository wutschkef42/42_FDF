/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 22:02:15 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:48:55 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putnull(t_size *sz)
{
	char	ret[6];
	int		i;

	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'u';
	ret[3] = 'l';
	ret[4] = 'l';
	ret[5] = ')';
	i = 0;
	while (i < 6)
		fillbuffer(ret[i++], sz);
	return (1);
}

void		fill_ze(t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		fillbuffer('0', sz);
		i++;
	}
}

void		fill_sp(t_size *sz, int nsp)
{
	int		i;

	i = 0;
	while (i < nsp)
	{
		fillbuffer(' ', sz);
		i++;
	}
}

void		putsign(t_size *sz, t_fwp *fwp)
{
	if (fwp->fi & fl_ne)
		fillbuffer('-', sz);
	else if (fwp->fi & fl_pl)
		fillbuffer('+', sz);
	else if (fwp->fi & fl_sp)
		fillbuffer(' ', sz);
}

void		put_hex_prfx(t_size *sz, char c)
{
	char	pref[2];
	int		i;

	pref[0] = '0';
	pref[1] = c;
	i = 0;
	while (i < 2)
		fillbuffer(pref[i++], sz);
}
