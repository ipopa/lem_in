#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include "libft.h"

typedef struct s_map t_map;

struct s_map
{
  t_list *vertices;
  t_list *edges;
  int ants;
};


int	get_next_line(int const fd, char **line);

#endif
