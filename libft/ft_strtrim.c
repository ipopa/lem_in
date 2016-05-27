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

char	*ft_strtrim(char const *s)
{
	int len;

	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s) - 1;
	while (len > 0 && s[len] && ft_isspace(s[len]))
		len--;
	return (ft_strsub(s, 0, len + 1));
}
