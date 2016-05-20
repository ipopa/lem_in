/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:13:22 by sbeaufil          #+#    #+#             */
/*   Updated: 2016/05/19 15:12:59 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_searchchr(const char *s, int (*f)(char))
{
  int i;

  i = 0;
  while (s[i] && !(*f)(s[i++]))
    {
    }
  return (i);
}
