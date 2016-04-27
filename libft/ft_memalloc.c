/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:07:40 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/14 19:18:20 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	i = 0;
	if ((s = (unsigned char*)malloc(size)))
	{
		while (i < size)
		{
			s[i] = 0;
			i++;
		}
	}
	return ((void*)s);
}
