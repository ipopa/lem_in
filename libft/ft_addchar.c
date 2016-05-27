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

void		ft_addchar(char **str, char c)
{
	char	*tmp;
	char	*tmp2;
	int		index;

	index = -1;
	if (*str)
		tmp = ft_strdup(*str);
	else
		tmp = ft_strdup("");
	ft_strdel(str);
	tmp2 = malloc(sizeof(char) * (ft_strlen(tmp) + 2));
	while (tmp[++index])
		tmp2[index] = tmp[index];
	tmp2[index] = c;
	tmp2[index + 1] = '\0';
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
