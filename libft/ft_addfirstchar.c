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

void		ft_addfirstchar(char **str, char c)
{
	char	*tmp;
	char	*tmp2;
	int		index;
	int		cp;

	index = 0;
	cp = 0;
	if (*str)
		tmp = ft_strdup(*str);
	else
		tmp = ft_strdup("");
	ft_strdel(str);
	tmp2 = malloc(sizeof(char) * (ft_strlen(tmp) + 2));
	tmp2[cp++] = c;
	while (tmp[index])
		tmp2[cp++] = tmp[index++];
	tmp2[cp] = '\0';
	*str = ft_strdup(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
