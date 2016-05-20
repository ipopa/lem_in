#include "libft.h"

size_t  ft_words(char const *s, int (*f)(char))
{
  int   i;
  size_t        size;

  i = 0;
  size = 0;
  while (s[i] && (*f)(s[i]))
    i++;
  while (s[i])
    {
      while (s[i] && (*f)(s[i]))
        i++;
      if (s[i])
        {
          while (s[i] && !(*f)(s[i]))
            i++;
          size++;
        }
    }
  return (size);
}
