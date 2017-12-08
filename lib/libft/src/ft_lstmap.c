/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:17:02 by plamusse          #+#    #+#             */
/*   Updated: 2017/05/01 13:34:33 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*lst_tmp;
	t_list	*ret_tmp;

	if (!lst || !f)
		return (NULL);
	lst_tmp = lst;
	ret = f(lst_tmp);
	ret->next = NULL;
	ret_tmp = ret;
	while (lst_tmp->next && ret_tmp)
	{
		ret_tmp->next = f(lst_tmp->next);
		lst_tmp = lst_tmp->next;
		ret_tmp = ret_tmp->next;
	}
	ret_tmp->next = NULL;
	return (ret);
}
