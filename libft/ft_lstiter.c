/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:35:43 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/01/26 18:14:11 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == NULL)
		return ;
	if (lst && f)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			(*f)(tmp);
			tmp = tmp->next;
		}
	}
}
