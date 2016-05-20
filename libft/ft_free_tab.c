#include "libft.h"

void ft_free_tab(char **tab)
{
  int i;

  if (tab)
    {
      i = 0;
      while(tab[i])
	{
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
}
