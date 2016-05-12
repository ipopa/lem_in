/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeaufil <sbeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 19:09:26 by sbeaufil          #+#    #+#             */
/*   Updated: 2015/03/03 16:54:01 by sbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_dellist(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return (NULL);
	else
	{
		tmp = list->next;
		free(list->str);
		free(list);
		return (ft_dellist(tmp));
	}
}

t_list		*add_link(t_list *list, char *str)
{
	t_list	*nouvelelement;
	t_list	*tmp;

	nouvelelement = malloc(sizeof(t_list));
	nouvelelement->str = ft_strdup(str);
	nouvelelement->next = NULL;
	if (list == NULL)
		return (nouvelelement);
	else
	{
		tmp = list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nouvelelement;
		return (list);
	}
}

int			transform_list_to_str(t_list *list, int len, char **line)
{
	char	*str;
	t_var	e;
	t_list	*tmp;

	e.i = 0;
	if ((str = (char*)malloc(sizeof(str) * (len + 1))) == NULL)
		return (-1);
	while (list != NULL && e.i < len)
	{
		e.j = 0;
		while ((list->str)[e.j] != '\0' && (list->str)[e.j] != '\n' \
				&& e.j < len && e.j < BUFF_SIZE)
		{
			str[e.i++] = (list->str)[e.j++];
		}
		str[e.i] = (list->str)[e.j];
		tmp = list->next;
		free(list->str);
		list = tmp;
	}
	str[e.i] = '\0';
	ft_dellist(list);
	*line = ft_strdup(str);
	free (str);
	return (0);
}

int			read_file(t_get cp, t_list *list, char **rest, char **line)
{
	t_int		e;
	char		buf[BUFF_SIZE + 1];

	e.ret = 0;
	*rest = NULL;
	while ((e.ret = read(cp.fd, buf, BUFF_SIZE)))
	{
		if (e.ret == -1)
			return (-1);
		buf[e.ret] = '\0';
		e.i = -1;
		list = add_link(list, buf);
		while (buf[++e.i] != '\0' && e.i < BUFF_SIZE)
		{
			if (buf[e.i] == '\n')
			{
				transform_list_to_str(list, cp.len, line);
				*rest = ft_strdup(&(buf[e.i + 1]));
				return (1);
			}
			cp.len++;
		}
	}
	transform_list_to_str(list, cp.len, line);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*rest[1024];
	t_list			*list;
	t_get			cp;

	cp.len = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	list = NULL;
	if (rest[fd])
	{
		list = add_link(list, rest[fd]);
		cp.len = -1;
		while (rest[fd][++cp.len] != '\0')
			if (rest[fd][cp.len] == '\n')
			{
				transform_list_to_str(list, cp.len, line);
				rest[fd] = ft_strdup(&(rest[fd][cp.len + 1]));
				return (1);
			}
	}
	free(rest[fd]);
	rest[fd] = NULL;
	cp.fd = fd;
	return (read_file (cp, list, &rest[fd], line));
}
