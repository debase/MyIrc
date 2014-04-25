/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/debas_e
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 23 13:09:41 2014 Etienne
** Last update Wed Apr 23 16:16:05 2014 Etienne
*/

#include "str_to_wordtab.h"

char            **realloc_str_tab(char **old, int new_size)
{
  char          **new;
  int           index;

  index = 0;
  if ((new = malloc(new_size * sizeof(char *))) == NULL)
    return (NULL);
  while (old[index])
    {
      if ((new[index] = strdup(old[index])) == NULL)
        return (NULL);
      free(old[index]);
      index++;
    }
  free(old);
  return (new);
}

char            **str_to_wordtab(char *str, char *token)
{
  char          **ret;
  int           nb_elem;
  char          *tmp;
  char          *save;

  if ((str = strdup(str)) == NULL)
      return (STR_WORD_TAB_ERROR);
  if ((ret = malloc(1 * sizeof(char *))) == NULL)
    return (STR_WORD_TAB_ERROR);
  ret[0] = NULL;
  nb_elem = 1;
  while ((tmp = strtok_r((nb_elem == 1 ? str : NULL), token, &save)) != NULL)
    {
      nb_elem = nb_elem + 1;
      ret = realloc_str_tab(ret, nb_elem);
      if (ret == NULL)
        return (STR_WORD_TAB_ERROR);
      ret[nb_elem - 1] = NULL;
      if ((ret[nb_elem - 2] = strdup(tmp)) == NULL)
	return (STR_WORD_TAB_ERROR);
    }
  return (ret);
}
