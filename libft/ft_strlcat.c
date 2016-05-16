/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:28:36 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 18:01:14 by sbeaufil         ###   ########.fr       */
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
