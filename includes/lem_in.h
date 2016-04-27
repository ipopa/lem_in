#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include "get_next_line.h"

typedef struct s_map t_map;

struct s_map
{
  t_list *vertices;
  t_list *edges;
  int ants;
};

#endif
