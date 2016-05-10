#include "lem_in.h"

size_t	ft_words(char const *s, char c)
{
  int	i;
  size_t	size;

  i = 0;
  size = 0;
  while (s[i] && s[i] == c)
    i++;
  while (s[i])
    {
      while (s[i] && s[i] == c)
	i++;
      if (s[i])
	{
	  while (s[i] && s[i] != c)
	    i++;
	  size++;
	}
    }
  return (size);
}

void free_vertices(t_vert *vertices)
{
  while(vertices)
    {
      while(vertices->edges)
	{
	  free(vertices->edges);
	  vertices->edges = vertices->edges->next;
	}
      free(vertices->name);
      free(vertices->wt);
      free(vertices);
      vertices = vertices->next;
    }
}

void destroy_map(t_map *graph)
{
  int i;

  free_vertices(graph->vertices);
 
  while(graph->listpath)
    {
      if (graph->listpath->cur)
	free(graph->listpath->cur);
      while (graph->listpath->path)
	{
	  free(graph->listpath->path);
	  graph->listpath->path = graph->listpath->path->next;
	}
      free(graph->listpath);
      graph->listpath = graph->listpath->next;
    }
  i = 0;
  while(i <= graph->maxpath)
    {
      free(graph->tabpath[i]);
      i++;
    }
  free(graph->tabpath);
  free(graph);
  // while(42) {
  // }
}

void free_tab(char **tab) {
  int j;

  j = 0;

  if (tab) {
    while (tab[j]) {
      free(tab[j]);
      j++;
    }
    free(tab);
  }
}
