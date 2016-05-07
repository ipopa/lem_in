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

void destroy_map(t_map *graph)
{
  while(graph->vertices != NULL)
    {
      while(graph->vertices->edges != NULL)
	{
	  free(graph->vertices->edges);
	  graph->vertices->edges = graph->vertices->edges->next;
	}
      free(graph->vertices->name);
      free(graph->vertices->wt);
      free(graph->vertices);
      graph->vertices = graph->vertices->next;
    }
  while(graph->listpath != NULL)
    {
      free(graph->listpath->path);
      free(graph->listpath);
      graph->listpath = graph->listpath->next;
    }
  free(graph);
  //  while(42) {
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
