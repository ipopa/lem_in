/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 13:31:43 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/04 13:34:59 by sbeaufil         ###   ########.fr       */
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
