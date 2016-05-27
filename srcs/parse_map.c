/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipopa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:42:05 by ipopa             #+#    #+#             */
/*   Updated: 2016/05/27 11:43:30 by ipopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_line(t_map *graph, char *line, bool start, bool end)
{
	if (ft_searchchr(line, &ft_isspace) && ft_words(line, &ft_isspace) == 3)
	{
		if (add_vert(graph, line, start, end) != 1)
			return (-1);
	}
	else if (ft_searchchr(line, &my_isline) && ft_words(line, &my_isline) == 2)
	{
		if (add_edge(graph, line) == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

void	join_to_map(t_map *graph, char *line)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (graph->mapcount + 2));
	i = 0;
	while (i < graph->mapcount)
	{
		tmp[i] = graph->map[i];
		i++;
	}
	tmp[i] = ft_strdup(line);
	tmp[i + 1] = NULL;
	free(graph->map);
	graph->map = tmp;
	graph->mapcount++;
}

int		test_parse_line(t_map *graph, char *line)
{
	if (line[0] == 'L' || parse_line(graph, line, graph->start_b,\
			graph->end_b) == -1)
		return (0);
	graph->start_b = false;
	graph->end_b = false;
	return (1);
}

void	get_map(t_map *graph)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) >= 0)
	{
		if (test_start(graph, ft_strtrim(line)) == -1)
			break ;
		else if (test_end(graph, ft_strtrim(line)) == -1)
			break ;
		else if (line[0] == '#')
			;
		else
		{
			if (!test_parse_line(graph, line))
				break ;
		}
		join_to_map(graph, line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
	}
	if (line)
		free(line);
}

int		parse_map(t_map *graph)
{
	graph->start_b = false;
	graph->end_b = false;
	graph->error = false;
	get_map(graph);
	if (graph->end_b || graph->start_b || !graph->start ||\
				!graph->end || graph->error)
		return (-1);
	if (ft_algo(graph) == -1)
		return (-1);
	return (1);
}
