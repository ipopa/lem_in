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

char		ft_hexa(unsigned int c)
{
	if (c < 10)
		return (c + '0');
	else
		return ((c % 10) + 'a');
}

char		*ft_htoa(unsigned int c)
{
	char	hexa[8];
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (c > 16)
	{
		hexa[i++] = ft_hexa(c % 16);
		c = c / 16;
	}
	hexa[i++] = ft_hexa(c);
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i--)
		ret[j++] = hexa[i];
	ret[j] = 0;
	return (ret);
}
