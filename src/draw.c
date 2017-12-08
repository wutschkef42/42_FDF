/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:04:31 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/07 23:43:32 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*get_by_id(t_list *points, unsigned int id)
{
	int		i;
	t_list	*tmp;

	if (!points)
		return (NULL);
	tmp = points;
	i = 0;
	while (i++ < id)
		if (tmp->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

void			draw_surface(t_list *points, int row, int col, t_mlx *env)
{
	t_px *a;
	t_px *b;

	a = ((t_px*)((get_by_id(points, row * env->xmax + col)->content)));
	if (a->flag == 1)
		return ;
	else
		a->flag = 1;
	if (col < env->xmax - 1)
	{
		b = (t_px*)((get_by_id(points, row * env->xmax + col + 1)->content));
		plot_segment(a, b, env);
		draw_surface(points, row, col + 1, env);
	}
	if (row < env->ymax)
	{
		b = (t_px*)((get_by_id(points, (row + 1) * env->xmax + col)->content));
		plot_segment(a, b, env);
		draw_surface(points, row + 1, col, env);
	}
}
