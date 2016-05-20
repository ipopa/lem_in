#include "lem_in.h"

int count_edge(t_vert *vert)
{
  int i;
  t_edge *tmp;

  i = 0;
  tmp = vert->edges;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return i;
}

t_vert *find_vert(t_vert *vert, char *name)
{
  t_vert *tmp;

  tmp = vert;
  while (tmp != NULL)
    {
      if (ft_strequ(tmp->name, name))
        return (tmp);
      tmp = tmp->next;
    }
  return NULL;
}

void free_vertices(t_vert *vertices)
{
  t_vert *tmpV;
  t_edge *tmpE;

  while (vertices)
    {
      while (vertices->edges)
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

void free_tabpath(t_map *graph)
{
  int i;

  if (graph->tabpath)
    {
      i = 0;
      while (i < graph->maxpath)
	{
	  free(graph->tabpath[i]);
	  i++;
	}
      free(graph->tabpath);
    }
}

void destroy_map(t_map *graph)
{
  int i;
  t_listpath *tmpL;
  t_path *tmpP;

  free_vertices(graph->vertices);
  while (graph->listpath)
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
  ft_free_tab(graph->map);
  free(graph);
  //  while(42) {
  //}
}
