/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:37:34 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/07 22:58:38 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		plot_pixel(int x, int y, t_mlx *env)
{
	int	*data_addr;

	data_addr = env->data;
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		*(data_addr + (WIN_WIDTH * y) + x) = 0xFFFFFF;
}

static void	init_seg(t_px *a, t_px *b, t_seg *seg)
{
	seg->x1 = a->isox;
	seg->x2 = b->isox;
	seg->y1 = a->isoy;
	seg->y2 = b->isoy;
	seg->dx = seg->x2 - seg->x1;
	seg->dy = seg->y2 - seg->y1;
	seg->dx = seg->dx < 0 ? -seg->dx : seg->dx;
	seg->dy = seg->dy < 0 ? -seg->dy : seg->dy;
	seg->incx = seg->x2 < seg->x1 ? -1 : 1;
	seg->incy = seg->y2 < seg->y1 ? -1 : 1;
	seg->x = seg->x1;
	seg->y = seg->y1;
}

static void	plot_segmentx(t_seg *seg, t_mlx *env)
{
	int	e;
	int	i;

	plot_pixel(seg->x, seg->y, env);
	e = 2 * seg->dy - seg->dx;
	seg->inc1 = 2 * (seg->dy - seg->dx);
	seg->inc2 = 2 * seg->dy;
	i = 0;
	while (i < seg->dx)
	{
		if (e >= 0)
		{
			seg->y += seg->incy;
			e += seg->inc1;
		}
		else
		{
			e += seg->inc2;
		}
		seg->x += seg->incx;
		plot_pixel(seg->x, seg->y, env);
		i++;
	}
}

static void	plot_segmenty(t_seg *seg, t_mlx *env)
{
	int	e;
	int	i;

	plot_pixel(seg->x, seg->y, env);
	e = 2 * seg->dx - seg->dy;
	seg->inc1 = 2 * (seg->dx - seg->dy);
	seg->inc2 = 2 * seg->dx;
	i = 0;
	while (i < seg->dy)
	{
		if (e >= 0)
		{
			seg->x += seg->incx;
			e += seg->inc1;
		}
		else
		{
			e += seg->inc2;
		}
		seg->y += seg->incy;
		plot_pixel(seg->x, seg->y, env);
		i++;
	}
}

void		plot_segment(t_px *a, t_px *b, t_mlx *env)
{
	t_seg	seg;

	init_seg(a, b, &seg);
	if (seg.dx > seg.dy)
		plot_segmentx(&seg, env);
	else
		plot_segmenty(&seg, env);
}
