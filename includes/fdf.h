/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:48:43 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/08 01:28:26 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# include "../lib/libft/includes/ft_printf.h"


# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1200
# define ZOOM 		2


typedef struct			s_seg
{
	int	x;
	int	y;
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	incx;
	int	incy;
	int	inc1;
	int	inc2;
}						t_seg;

typedef struct			s_img
{
		int				bpp;
		int				sl;
		int				endian;
}						t_img;;

typedef struct			s_mlx
{
	int					*data;
	void				*mlx;
	void				*win;
	void				*img;
	int					xmax;
	int					ymax;
	int					isox_max;
	int					isox_min;
	int					isoy_max;
	int					isoy_min;
	int					gutter_width;
	int					offset_x;
	int					offset_y;
	int					xabsmax;
	int					xabsmin;
	int					yabsmax;
	int					yabsmin;
}						t_mlx;


typedef struct			s_px
{
	int		flag;
	int		x;
	int		y;
	int		z;
	int		isox;
	int		isoy;
	int		color;
}						t_px;

int		map_parser(t_list **lst, int fd);
void	plot_pixel(int x, int y, t_mlx *env);
void	to_pixel(t_list *points, t_mlx *env);
void	plot_segment(t_px *a, t_px *b, t_mlx *env);
void	draw_surface(t_list *points, int x, int y, t_mlx *env);
int     quit(int keycode, void *param);

void	get_offset(t_mlx *env);
void	get_max_coord(t_mlx *env, t_list *points);
void	get_iso_dim(t_mlx *env, t_list *points);
void	get_absolute_dimensions(t_mlx *env, t_list *points);
void	to_pixel(t_list *points, t_mlx *env);
void	apply_offset(t_mlx *env, t_list *points);
void	get_offset(t_mlx *env);
void	set_gutter(t_mlx *env);






#endif
