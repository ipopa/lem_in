#include "lem_in.h"

void print_vertice(t_vert *vert)
{
  if (vert->end)
    printf("- vertice end -\n");
  if (vert->start)
    printf("- vertice start -\n");
  printf("name = %s; wt = %d; x = %d; y = %d\n", vert->name, *(vert->wt), vert->x, vert->y);
  if (vert->occ)
    printf("- vertice occuped -\n");
}

void print_print(int i, char *str)
{
  ft_putstr("L");
  ft_putnbr(i);
  ft_putstr("-");
  ft_putstr(str);
  ft_putstr(" ");
}

int print_ant(char **ants, t_path *path, int i)
{
  int j;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  j = i;
  tmp = path->next;
  if (ants[j])
    {
      while (tmp != NULL)
	{
	  if (ft_strequ(tmp->vertices->name, ants[j]))
	    {
	      tmp = tmp->next;
	      break ;
	    }
	  j++;
	  tmp = tmp->next;
	}
      if (tmp)
	{
	  ants[j] = ft_strdup(tmp->vertices->name);
	  print_print(j + 1, ants[j]);
	}
    }
  else
    {
      ants[j] = ft_strdup(tmp->vertices->name);
      print_print(j + 1, ants[j]);
    }
  return 0;
}

void add_to_tab(char **tab, int nb, t_path *path, t_map *graph)
{
  int i;
  char *tmpStr;
  t_path *tmp;
  char ant[4];
  char *str;

  tmp = path->next;

  //il faut ft_itoa 
  
  ant[0] = 'L';
  ant[1] = nb + 48 + 1;
  ant[2] = '-';
  ant[3] = 0;

  i = 0;
  while (tmp)
    {
      str = ft_strjoin(ant, tmp->vertices->name);
      tmpStr = ft_strjoin(str, " ");
      free(str);
      if (tab[i])
	{
	  str = ft_strjoin(tab[i], tmpStr);
	  free(tmpStr);
	  free(tab[i]);
	  tab[i] = ft_strdup(str);
	  free(str);
	}
      else
	{
	  tab[i] = ft_strdup(tmpStr);
	  free(tmpStr);
	}
      i++;
      tmp = tmp->next;
    }
}

void print_graph(t_map *graph, int **tab)
{
  int i;
  int nb;
  t_listpath *tmpLP;
  char **tabAnts;
  int *nbPath;
  int tmpJ;
  
  i = 1;
  nb = 0;
  tmpLP = graph->listpath;
  /*  tabAnts = (char **)malloc(sizeof(char *) * (graph->ants + 1));
  nbPath = (int *)malloc(sizeof(int) * (graph->ants + 1));

  while(nb < graph->ants)
    {
      tabAnts[nb] = 0;
      nb++;
    }
  nb = 0;
  while (nb < graph->ants)
    {
      nbPath[nb] = 0;
      nb++;
    }
  int test = 0;
  int tmpTest = 1;
  int k = graph->nbpath;
 
  char *fin = ft_strdup("9");
  */
  char **tabAll = (char **)malloc(sizeof(char *) * (graph->ants + 1));
  int wpath = 1;
  int j;

  nb = 0;
  while(nb < graph->ants)
    {
      if (tab[wpath - 1][1] > 0)
	{
	  tmpLP = graph->listpath;
	  j = 0;
	  while (j < wpath - 1)
	    {
	      tmpLP = tmpLP->next;
	      j++;
	    }
	  if (tmpLP)
	    {
	      add_to_tab(tabAll, nb, tmpLP->path, graph);
	      tab[wpath - 1][1]--;
	    }
	}
      wpath++;
      if (wpath > graph->nbpath)
	wpath = 1;
      nb++;
    }
  j = 0;
  while(j < graph->ants && tabAll[j])
    {
      printf("%s\n", tabAll[j]);
      j++;
    }

  /*  nb = 0;
      while(42 == 2)
      {
      if (!nbPath[nb])
      {
      if (tab[i - 1][1])
      {
      nbPath[nb] = i;
      tab[i - 1][1]--;
      }
      else
      {
      //	      printf("ca marche pas\n");
      tmpLP = tmpLP->next;
      if (!tmpLP)
      {
      i = 0;
      tmpLP = graph->listpath;
      }
      i++;
      continue ;
      }
      }
	
      if (nbPath[nb] == i)
      {
      if (!ft_strequ(tabAnts[nb], fin))
      {
      print_ant(tabAnts, tmpLP->path, nb);
      if (nb < graph->ants - 1)
      nb++;
      }
      }
      else 
      {
      if (ft_strequ(tabAnts[nb], fin))
      {
      if (nb < graph->ants - 1)
      nb++;
      }
      }

      tmpLP = tmpLP->next;

      if (nb == (graph->ants - 1) && ft_strequ(tabAnts[nb], fin))
      {
      ft_putstr("\n");
      break ;
      }      
      // tous les chemins ont ete explore
      if (!tmpLP)
      {
      test++;
      if (test == tmpTest)
      {
	    
      test = 0;
      tmpTest *= 2;
      nb = 0;
      ft_putstr("\n");
      }
      i = 0;
      tmpLP = graph->listpath;
      }
      i++;
      }*/
}
