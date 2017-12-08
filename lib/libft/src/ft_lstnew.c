/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:09:05 by plamusse          #+#    #+#             */
/*   Updated: 2017/04/26 20:26:07 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	if (!(elem = (t_list*)malloc(sizeof(*elem))))
		return (NULL);
	elem->content = (content) ? ft_memcpy(malloc(sizeof(*content) *
						content_size), content, content_size) : NULL;
	elem->content_size = (elem->content) ? content_size : 0;
	elem->next = NULL;
	return (elem);
}
