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
  t_vert *tmpV;
  t_edge *tmpE;

  while(vertices)
    {
      while(vertices->edges)
	{
	  tmpE = vertices->edges;
	  vertices->edges = vertices->edges->next;
	  free(tmpE);
	}
      free(vertices->name);
      free(vertices->wt);
      tmpV = vertices;
      vertices = vertices->next;
      free(tmpV);
    }
}

void destroy_map(t_map *graph)
{
  int i;
  t_listpath *tmpL;
  t_path *tmpP;

  free_vertices(graph->vertices);
 
  while(graph->listpath)
    {
      while (graph->listpath->path)
	{
	  tmpP = graph->listpath->path;
	  graph->listpath->path = graph->listpath->path->next;
	  free(tmpP);
	}
      tmpL = graph->listpath;
      graph->listpath = graph->listpath->next;
      free(tmpL);
    }
  i = 0;
  while(i < graph->maxpath)
    {
      free(graph->tabpath[i]);
      i++;
    }
  free(graph->tabpath);
  free(graph);
  //  while(42) {
  //}
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
