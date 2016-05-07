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
  while(vertices != NULL)
    {
      while(vertices->edges != NULL)
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
  free_vertices(graph->vertices);
 
  while(graph->listpath != NULL)
    {
      if (graph->listpath->cur != NULL)
	{
	  //  free_vertices(graph->listpath->cur->vertices);
	  free(graph->listpath->cur);
	}
      if (graph->listpath->path != NULL)
	{
	  //  free_vertices(graph->listpath->path->vertices);
	  free(graph->listpath->path);
	}
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
