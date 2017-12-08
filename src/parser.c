/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <plamusse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:42:45 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/08 01:33:10 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			stock_coord(t_px *px, char *str)
{
	px->flag = 0;
	px->z = ft_atoi(str);
	px->isox = (px->x - px->y);
	px->isoy = (px->x + px->y) - px->z;
}

static int		validate_format(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] == ',' && str[++i] == '0' && str[++i] == 'x')
			i++;
		while (str[i] && ft_ishexa(str[i]))
			i++;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

static int		stock_lst(t_list **lst, char **tab, int row)
{
	t_px		px;
	int			col;
	int			ret;
	t_list		*lst_ret;

	px.y = row;
	col = 0;
	ret = 1;
	while (tab[col] && ret && lst_ret)
	{
		px.x = col;
		if ((ret = validate_format(tab[col])))
		{
			stock_coord(&px, tab[col]);
			lst_ret = ft_lst_push_back(lst, ft_lstnew(&px, sizeof(px)));
		}
	   col++;
	}
	if (ret && lst_ret)
		return (1);
	return (0);
}	

int		map_parser(t_list **lst, int fd)
{
	char	*line = NULL;
	char	**tab;
	int		row;
	int		brk;
	int		ret;

	row = 0;
	while ((ret = get_next_line(fd, &line)) && ret != -1 && brk)
	{
		tab = ft_strsplit(line, ' ');
		free(line);
		if (tab == 0 && (brk = 0))
			break;
		brk = stock_lst(lst, tab, row++);
		ft_tabclr(tab);
	}
	close(fd);
	if (ret != -1 && brk)
		return (1);
	return (0);
}

void	to_pixel(t_list **points, t_mlx *env)
{
	t_list	*tmp;

	if (!*points)
		return;
	tmp = *points;
	while (tmp)
	{

		((t_px*)(tmp->content))->isox += ft_abs(env->isox_min);
		((t_px*)(tmp->content))->isoy += ft_abs(env->isoy_min);

				
		((t_px*)(tmp->content))->isox *= env->gutter_width;
		//((t_px*)(tmp->content))->isox += env->offset_x;
		((t_px*)(tmp->content))->isoy *= env->gutter_width / 2;
	//	((t_px*)(tmp->content))->isoy += env->offset_y;
		
		tmp = tmp->next;
	}
}
