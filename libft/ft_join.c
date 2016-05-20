/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 15:27:47 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/06/02 15:27:51 by sbeaufil         ###   ########.fr       */
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
