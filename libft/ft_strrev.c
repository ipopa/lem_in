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

char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}
