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
