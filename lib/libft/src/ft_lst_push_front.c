/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:49:30 by plamusse          #+#    #+#             */
/*   Updated: 2017/12/07 12:28:50 by plamusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	new->next = tmp;
	*alst = new;
	return (new);
}
