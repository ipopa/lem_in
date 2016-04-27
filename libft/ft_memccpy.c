/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:59:27 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/12 15:07:38 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dstcpy;
	char	*srccpy;

	dstcpy = (char*)dst;
	srccpy = (char*)src;
	while (n-- > 0)
	{
		if ((*dstcpy++ = *srccpy++) == c)
			return (dstcpy);
	}
	return (NULL);
}
