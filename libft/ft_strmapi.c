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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapi;

	i = 0;
	if (s == NULL || (f) == NULL)
		return (NULL);
	mapi = (char*)malloc((ft_strlen(s) + 1) * sizeof(char*));
	if (mapi == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mapi[i] = (f)(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
