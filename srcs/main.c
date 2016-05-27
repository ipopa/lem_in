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

int		test_start(t_map *graph, char *line)
{
	int ret;

	ret = 1;
	if ((graph->start_b || graph->start) && ft_strequ(line, "##start"))
		ret = -1;
	else if (ft_strequ(line, "##start"))
		graph->start_b = true;
	free(line);
	return (ret);
}

int		test_end(t_map *graph, char *line)
{
	int ret;

	ret = 1;
	if ((graph->end_b || graph->end) && ft_strequ(line, "##end"))
		ret = -1;
	else if (ft_strequ(line, "##end"))
		graph->end_b = true;
	free(line);
	return (ret);
}

void	print_tab(t_path **tab, int max)
{
	int		i;
	bool	spacebool;

	i = 0;
	spacebool = false;
	while (i < max)
	{
		if (tab[i])
		{
			if (spacebool)
				ft_putchar(' ');
			spacebool = true;
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr((tab[i])->vertices->name);
		}
		i++;
	}
}

int		main(void)
{
	char	*line;
	t_map	*graph;
	int		ret;
	int		ants;

	line = NULL;
	if ((ret = get_next_line(0, &line)) != -1 && (ft_atoi(line) > 0))
	{
		ants = ft_atoi(line);
		graph = init_map();
		graph->ants = ants;
		join_to_map(graph, line);
		if (parse_map(graph) == -1)
			error();
		destroy_map(graph);
	}
	else
		error();
	if (line)
		free(line);
	return (0);
}
