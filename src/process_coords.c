/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwutschk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:30:08 by fwutschk          #+#    #+#             */
/*   Updated: 2017/12/08 19:30:10 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_coord(t_mlx *env, t_list *points)
{
	env->xmax = 0;
	env->ymax = 0;
	while (points)
	{
		if (env->xmax <= ((t_px*)points->content)->x)
			env->xmax = ((t_px*)points->content)->x;
		if (env->ymax <= ((t_px*)points->content)->y)
			env->ymax = ((t_px*)points->content)->y;
		points = points->next;
	}
	env->xmax++;
	env->ymax++;
}

void	get_iso_dim(t_mlx *env, t_list *points)
{
	env->isox_max = 0;
	env->isox_min = 0;
	env->isoy_max = 0;
	env->isoy_min = 0;
	while (points)
	{
		if (env->isox_max <= ((t_px*)points->content)->isox)
			env->isox_max = ((t_px*)points->content)->isox;
		if (env->isoy_max <= ((t_px*)points->content)->isoy)
			env->isoy_max = ((t_px*)points->content)->isoy;
		if (env->isox_min >= ((t_px*)points->content)->isox)
			env->isox_min = ((t_px*)points->content)->isox;
		if (env->isoy_min >= ((t_px*)points->content)->isoy)
			env->isoy_min = ((t_px*)points->content)->isoy;
		points = points->next;
	}
}

void	get_absolute_dimensions(t_mlx *env, t_list *points)
{
	env->xabsmax = 0;
	env->xabsmin = 0;
	env->yabsmax = 0;
	env->yabsmin = 0;
	while (points)
	{
		if (env->xabsmax <= ((t_px*)points->content)->isox)
			env->xabsmax = ((t_px*)points->content)->isox;
		if (env->yabsmax <= ((t_px*)points->content)->isoy)
			env->yabsmax = ((t_px*)points->content)->isoy;
		if (env->xabsmin >= ((t_px*)points->content)->isox)
			env->xabsmin = ((t_px*)points->content)->isox;
		if (env->yabsmin >= ((t_px*)points->content)->isoy)
			env->yabsmin = ((t_px*)points->content)->isoy;
		points = points->next;
	}
}

void	to_pixel(t_list *points, t_mlx *env)
{
	if (!points)
		return ;
	while (points)
	{
		((t_px*)((points)->content))->isox += ft_abs(env->isox_min);
		((t_px*)((points)->content))->isoy += ft_abs(env->isoy_min);
		((t_px*)((points)->content))->isox *= env->gutter_width;
		((t_px*)((points)->content))->isoy *= env->gutter_width / 2;
		(points) = (points)->next;
	}
}

void	apply_offset(t_mlx *env, t_list *points)
{
	while (points)
	{
		((t_px*)(points->content))->isox += env->offset_x;
		((t_px*)(points->content))->isoy += env->offset_y;
		points = points->next;
	}
}
