/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indent_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:35:00 by plamusse          #+#    #+#             */
/*   Updated: 2017/09/06 19:41:56 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	wchar2oct(unsigned int tmp, t_size *sz, unsigned int msk)
{
	int				oct1;
	int				oct2;

	oct2 = (tmp << 26) >> 26;
	oct1 = ((tmp >> 6) << 27) >> 27;
	fillbuffer((unsigned char)((msk >> 8) | oct1), sz);
	fillbuffer((unsigned char)(((msk << 24) >> 24) | oct2), sz);
}

static void	wchar3oct(unsigned int tmp, t_size *sz, unsigned int msk)
{
	int				oct1;
	int				oct2;
	int				oct3;

	oct3 = (tmp << 26) >> 26;
	oct2 = ((tmp >> 6) << 26) >> 26;
	oct1 = ((tmp >> 12) << 28) >> 28;
	fillbuffer((unsigned char)((msk >> 16) | oct1), sz);
	fillbuffer((unsigned char)(((msk << 16) >> 24) | oct2), sz);
	fillbuffer((unsigned char)(((msk << 24) >> 24) | oct3), sz);
}

static void	wchar4oct(unsigned int tmp, t_size *sz, unsigned int msk)
{
	int				oct1;
	int				oct2;
	int				oct3;
	int				oct4;

	oct4 = (tmp << 26) >> 26;
	oct3 = ((tmp >> 6) << 26) >> 26;
	oct2 = ((tmp >> 12) << 26) >> 26;
	oct1 = ((tmp >> 18) << 29) >> 29;
	fillbuffer((unsigned char)((msk >> 24) | oct1), sz);
	fillbuffer((unsigned char)(((msk << 8) >> 24) | oct2), sz);
	fillbuffer((unsigned char)(((msk << 16) >> 24) | oct3), sz);
	fillbuffer((unsigned char)(((msk << 24) >> 24) | oct4), sz);
}

void		ft_putwchar(wchar_t arg, t_size *sz)
{
	unsigned int	msk;
	unsigned int	tmp;

	tmp = (unsigned int)arg;
	if ((arg < 0 || arg > 0X10FFFF) && (sz->er = -1))
		return ;
	if (!(arg >> 7))
		fillbuffer((unsigned char)arg, sz);
	else if (!(arg >> 11) && (msk = 49280))
		wchar2oct(tmp, sz, msk);
	else if (!(arg >> 16) && (msk = 14712960))
		wchar3oct(tmp, sz, msk);
	else if ((msk = 4034953344))
		wchar4oct(tmp, sz, msk);
}
