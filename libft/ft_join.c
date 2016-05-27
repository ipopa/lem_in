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

char	*ft_join(char *s, char c)
{
	char	*join;
	int		i;

	i = 0;
	if (s == NULL || c == '\0')
		return (s);
	if (!(join = (char*)malloc((ft_strlen(s) + 2) * sizeof(char))))
		return (NULL);
	while (s[i] != '\0')
	{
		join[i] = s[i];
		i++;
	}
	join[i++] = c;
	join[i] = '\0';
	return (join);
}
