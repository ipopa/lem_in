/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:42:05 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/27 11:42:06 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tmp;
	t_list	*link;

	if (!lst || !f)
		return (NULL);
	link = f(lst);
	if ((map = ft_lstnew(link->content, link->content_size)))
	{
		tmp = map;
		lst = lst->next;
		while (lst)
		{
			link = f(lst);
			if (!(tmp->next = ft_lstnew(link->content, link->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (map);
}
