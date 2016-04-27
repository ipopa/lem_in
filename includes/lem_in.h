#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdbool.h>
#include <math.h>
#include "../libft/libft.h"
typedef struct s_map t_map;
typedef struct s_vert t_vert;

struct s_map
{
  t_vert *vertices;
  int ants;
};

struct s_vert
{
  bool start;
  bool end;
  bool occ;
  int wt;
  struct s_vert *edges;
  struct s_vert *orig;
  struct s_vert *next;
  int x;
  int y;
};

int parse_map(t_map *graph);

#endif
