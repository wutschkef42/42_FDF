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

static void	init_env(t_mlx *env, t_list **points)
{
	t_img	ctx;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	env->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int*)mlx_get_data_addr(env->img, &ctx.bpp, &ctx.sl,
		&ctx.endian);
}

int			main(int argc, char **argv)
{
	t_mlx	env;
	int		fd;
	t_list	*lst;

	lst = NULL;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("fd error\n");
		return (0);
	}
	map_parser(&lst, fd);
	init_env(&env, &lst);
	get_max_coord(&env, lst);
	env.gutter_width = WIN_WIDTH / (env.xmax * ZOOM);
	get_iso_dim(&env, lst);
	to_pixel(lst, &env);
	get_absolute_dimensions(&env, lst);
	get_offset(&env);
	apply_offset(&env, lst);
	draw_surface(lst, 0, 0, &env);
	mlx_put_image_to_window(env.data, env.win, env.img, 0, 0);
	mlx_key_hook(env.win, quit, (void*)lst);
	ft_lstdel(&lst, &ft_lst_memclr);
	mlx_loop(env.mlx);
	return (0);
}
