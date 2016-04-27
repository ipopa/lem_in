/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:40:50 by sbeaufil          #+#    #+#             */
/*   Updated: 2014/11/13 21:47:56 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrevcpy(char *dest, const char *src, size_t n)
{
  int i;

  i = 0;
  while (src[n] != '\0')
    {
      dest[i++] = src[n++];
    }
  dest[i] = '\0';
  return (dest);
}
