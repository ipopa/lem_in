#include "libft.h"

int             ft_strcasecmp(const char *s1, const char *s2)
{
  int i;

  i = 0;
  while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0' && s2[i] != '\0')
    i++;
  return ((unsigned char)ft_tolower(s1[i]) - (unsigned char)ft_tolower(s2[i]));
}
