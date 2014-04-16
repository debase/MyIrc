/*
** list.c for list in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 15:49:35 2014 Etienne
** Last update Wed Apr 16 17:47:25 2014 Etienne
*/

#include "list.h"

static	t_client	*create_list(t_client **list, size_t sizeblock)
{
  if ((*list = malloc(sizeblock)) != NULL)
    {
      memset((*list), 0, sizeblock);
      (*list)->next = NULL;
      (*list)->prev = NULL;
    }
  return (*list);
}

t_client		*push_back_list(t_client **list, size_t sizeblock)
{
  t_client		*new_elem;
  t_client		*tmp;

  if ((*list) == NULL)
    return (create_list(list, sizeblock));
  if (!(new_elem = malloc(sizeblock)))
    return (NULL);
  tmp = *list;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  memset(new_elem, 0, sizeblock);
  tmp->next = new_elem;
  new_elem->prev = tmp;
  new_elem->next = NULL;
  return (new_elem);
}

static void		rm_first_elem_list(t_client **list)
{
  t_client		*ptete;

  ptete = (*list);
  if ((*list)->next != NULL)
    {
      (*list)->next->prev = NULL;
      (*list) = (*list)->next;
    }
  free(ptete);
}

void			rm_elem_list(t_client **list, t_client *elem)
{
  t_client		*tmp;

  tmp = *list;
  if (tmp == elem)
    {
      rm_first_elem_list(list);
    }
  else
    {
      while (tmp != NULL)
	{
	  if (tmp == elem)
	    {
	      tmp->prev->next = tmp->next;
	      if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;
	      free(tmp);
	    }
	  tmp = tmp->next;
	}
    }
}

void		list_ptr_list(t_client *list)
{
  t_client	*tmp;

  tmp = list;
  printf ("LIST : %p\n", list);
  while (tmp)
    {
      printf ("ptr = %p\n", tmp);
      tmp = tmp->next;
    }
}
