/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:06:16 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/08 01:33:11 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_env(t_mlx *env)
{
	t_img	ctx;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int*)mlx_get_data_addr(env->img, &ctx.bpp , &ctx.sl, &ctx.endian);
}

/*static void	print_input(t_list *points)
{
	if (!points)
		return;
	while (points)
	{
		printf("x: %d / y: %d / z: %d / xiso: %d / yiso: %d\n", ((t_px*)(points->content))->x,
				((t_px*)(points->content))->y, ((t_px*)(points->content))->z, ((t_px*)(points->content))->isox,
				((t_px*)(points->content))->isoy);
		points = points->next;
	}
}
*/
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

void	get_offset(t_mlx *env)
{
	env->gutter_width = 1920 / 400;
									// atual x-min xmax 
	env->offset_x = (WIN_WIDTH - (env->xabsmax - env->xabsmin)) / 2;
	env->offset_y = (WIN_HEIGHT - (env->yabsmax - env->yabsmin)) / 2;
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
	printf("%d - %d - %d - %d\n", env->xabsmax, env->xabsmin, env->yabsmax, env->yabsmin);
}
	


int		main(int argc, char **argv)
{
	t_mlx	env;
	int		fd;
	t_list	*lst = NULL;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("fd error\n");
		return (0);
	}
	if (map_parser(&lst, fd))
		printf("map parsed\n");
	else
	{
		ft_lstdel(&lst, &ft_lst_memclr);
		close(fd);
		printf("map error\n");
		return (0);
	}
	init_env(&env);
	get_max_coord(&env, lst);
	get_iso_dim(&env, lst);
	
	to_pixel(&lst, &env);
	get_absolute_dimensions(&env, lst);

	get_offset(&env);

	printf("isox_min: %i, isox_max:%i, isoy_min:%i, isoy_max: %i, xmax: %i, ymax:%i\n", env.isox_min, env.isox_max, env.isoy_min, env.isoy_max, env.xmax, env.ymax);
	//	print_input(lst);

	t_px a;
	t_px b;
	a.isox = 0;
	a.isoy = 0;
	b.isox = 1000;
	b.isoy = 1000;
	plot_segment(&a, &b, &env);
	draw_surface(lst, 0, 0, &env);
	mlx_put_image_to_window(env.data, env.win, env.img, 0, 0);
/*	while (lst)
	{
		int x = ((t_px*)(lst->content))->isox;
		int y = ((t_px*)(lst->content))->isoy;
		plot_pixel(x, y, &env);
		lst = lst->next;
	}
*/
	ft_lstdel(&lst, &ft_lst_memclr);
	
	mlx_loop(env.mlx);
	return (0);
}
