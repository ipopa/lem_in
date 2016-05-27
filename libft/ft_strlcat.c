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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t x;
	size_t y;
	size_t i;

	x = ft_strlen(dst);
	y = ft_strlen(src);
	i = 0;
	if (size < x)
		return (y + size);
	while (src[i] != 0 && (x + i + 1) < (size))
	{
		dst[x + i] = src[i];
		i++;
	}
	if (i != size)
		dst[x + i] = '\0';
	return (x + y);
}
