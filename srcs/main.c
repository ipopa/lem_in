#include "lem_in.h"

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
	ants = ft_atoi(line);
	if ((ret = get_next_line(0, &line)) != -1 && (ants > 0))
	{
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
