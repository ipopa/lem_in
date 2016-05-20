/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfirstchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 13:33:59 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/04 14:04:32 by sbeaufil         ###   ########.fr       */
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
