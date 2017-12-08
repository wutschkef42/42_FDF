/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 13:28:29 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:20:34 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_fwp(t_fwp *fwp)
{
	fwp->fi = 0;
	fwp->wi = 0;
	fwp->pr = 0;
	fwp->fc = 0;
}

void		iflags(char *p, t_fwp *fwp)
{
	if (*p == '#' && (fwp->fi |= fl_ha))
		return ;
	else if (*p == '0' && (fwp->fi |= fl_ze))
		return ;
	else if (*p == '-' && (fwp->fi |= fl_mi))
		return ;
	else if (*p == '+' && (fwp->fi |= fl_pl))
		return ;
	else if (*p == ' ' && (fwp->fi |= fl_sp))
		return ;
}

void		cflag(char *p, t_fwp *fwp, const char *next)
{
	if (*p == 'h' && *next == 'h' && (fwp->fc |= fl_hh))
		return ;
	else if (*p == 'h' && !(fwp->fc & fl_hh) && (fwp->fc |= fl_h))
		return ;
	else if (*p == 'l' && (fwp->fc |= fl_l))
	{
		if (*next == 'l' && (fwp->fc |= fl_ll))
			;
		return ;
	}
	else if (*p == 'j' && (fwp->fc |= fl_j))
		return ;
	else if (*p == 'z' && (fwp->fc |= fl_z))
		return ;
}
