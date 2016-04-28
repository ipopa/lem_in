#include "libft.h"

int	ft_searchchr(char const *str, char c)
{
  int i;

  while(str[i] != '\0')
    {
      if (str[i] == c)
	return 1;
      i++;
    }
  return 0;
}
