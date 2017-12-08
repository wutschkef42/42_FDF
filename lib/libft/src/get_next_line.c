/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:39:13 by plamusse          #+#    #+#             */
/*   Updated: 2017/05/13 16:46:45 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list				*ft_lstupdate(int const fd, t_list *stock, t_list **pfirst)
{
	t_list			*lst_tmp;

	if (!stock)
	{
		if (!(stock = (t_list*)malloc(sizeof(*stock))))
			return (NULL);
		stock->content = ft_strnew(0);
		stock->content_size = (size_t)fd;
		stock->next = NULL;
		*pfirst = stock;
		return (stock);
	}
	lst_tmp = stock;
	while (lst_tmp && lst_tmp->content_size != (size_t)fd)
		lst_tmp = lst_tmp->next;
	if (lst_tmp && lst_tmp->content_size == (size_t)fd)
		return (lst_tmp);
	else if (!(lst_tmp = (t_list*)malloc(sizeof(*lst_tmp))))
		return (NULL);
	lst_tmp->content = ft_strnew(0);
	lst_tmp->content_size = (size_t)fd;
	lst_tmp->next = stock;
	*pfirst = lst_tmp;
	return (lst_tmp);
}

ssize_t				ft_retline_stockrest(char **line, t_list **stock,
		ssize_t ret)
{
	t_list			*lst_tmp;
	char			*tmp;
	size_t			i;

	lst_tmp = *stock;
	i = 0;
	if (ret == 0)
	{
		*line = ft_strdup(lst_tmp->content);
		free(lst_tmp->content);
		lst_tmp->content = ft_strnew(0);
		return (1);
	}
	tmp = lst_tmp->content;
	while (tmp[i] != '\n')
		i++;
	*line = ft_strsub(lst_tmp->content, 0, i);
	tmp = ft_strsub(lst_tmp->content, i + 1, ft_strlen(lst_tmp->content) - i);
	free(lst_tmp->content);
	lst_tmp->content = tmp;
	return (1);
}

ssize_t				ft_addbuff(int const fd, t_list *lst_tmp, ssize_t ret)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(lst_tmp->content, buff);
		free(lst_tmp->content);
		lst_tmp->content = tmp;
		ret = 1;
	}
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*stock = NULL;
	t_list			*lst_tmp;
	char			*str;
	ssize_t			ret;

	if (fd < 0 || !line)
		return (-1);
	lst_tmp = ft_lstupdate(fd, stock, &stock);
	ret = 1;
	while (ret >= 0)
	{
		str = ft_strchr(lst_tmp->content, '\n');
		if (str || ret == 0)
			return (ret = ft_retline_stockrest(line, &lst_tmp, ret));
		ret = ft_addbuff(fd, lst_tmp, ret);
		str = lst_tmp->content;
		if (ret == 0 && str[0] == '\0')
			return (0);
	}
	return (-1);
}
