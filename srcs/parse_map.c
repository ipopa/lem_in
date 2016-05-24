#include "lem_in.h"

int		parse_line(t_map *graph, char *line, bool start, bool end)
{
	int ret;

	if (ft_searchchr(line, &ft_isspace) && ft_words(line, &ft_isspace) == 3)
    {
		if ((ret = add_vert(graph, line, start, end)) != 1)
		{
			if (ret == -1)
				graph->error = true;
			return (-1);
		}
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
	char **tmp;
	int i;

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
	if (line[0] == 'L' || parse_line(graph, line, graph->startB, graph->endB) == -1)
		return (0);
	graph->startB = false;
	graph->endB = false;
	return (1);
}

void	get_map(t_map *graph)
{
	char *line;
	int ret;

	while ((ret = get_next_line(0, &line)) >= 0)
    {
		if (ft_strequ(line, "##start"))
			graph->startB = true;
		else if (ft_strequ(line, "##end"))
			graph->endB = true;
		else if(line[0] == '#')
		{
			free(line);
			continue ;
		}
		else
			if (!test_parse_line(graph, line))
				break ;
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
	graph->startB = false;
	graph->endB = false;
	graph->error = false;
	get_map(graph);
	if (graph->endB || graph->startB || !graph->start || !graph->end || graph->error)
		return (-1);
	if (ft_algo(graph) == -1)
		return (-1);
	return (1);
}
