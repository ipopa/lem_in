/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:15:45 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/01/26 19:50:59 by sbeaufil         ###   ########.fr       */
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
