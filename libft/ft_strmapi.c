/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 15:29:37 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/17 20:29:52 by sbeaufil         ###   ########.fr       */
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
