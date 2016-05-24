/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 16:17:50 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/24 16:56:14 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define BUFF_SIZE 8

typedef struct s_get	t_get;
typedef struct s_int	t_int;
typedef struct s_var	t_var;

struct					s_get
{
	int					i;
	int					len;
	int					fd;
	char				*tmp;
};

struct					s_int
{
	int ret;
	int i;
};

struct					s_var
{
	int i;
	int j;
};

int						get_next_line(int const ft, char **line);

#endif
