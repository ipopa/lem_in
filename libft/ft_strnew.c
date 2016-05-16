/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:41:57 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/13 17:41:30 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*s;
	unsigned int	len;

	len = 0;
	s = (char*)malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (len < size)
	{
		s[len] = '\0';
		len++;
	}
	s[len] = '\0';
	return (s);
}
