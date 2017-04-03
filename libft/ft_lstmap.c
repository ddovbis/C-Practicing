/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddovbis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:34:26 by ddovbis           #+#    #+#             */
/*   Updated: 2017/01/31 14:53:11 by ddovbis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*prev_list;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new_list = f(lst);
	prev_list = new_list;
	while (lst->next)
	{
		prev_list->next = f(lst->next);
		prev_list = prev_list->next;
		lst = lst->next;
	}
	return (new_list);
}
