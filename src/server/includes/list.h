/*
** list.h for list in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 16:00:09 2014 Etienne
** Last update Sun Apr 27 19:33:12 2014 Etienne
*/

#ifndef _LIST_H_
# define _LIST_H_

# include <stdlib.h>
# include <string.h>
# include "serveur.h"

t_client	*push_back_list(t_client **list, size_t sizeblock);
void		rm_elem_list(t_client **list, t_client *elem);
void		list_ptr_list(t_client *list);

#endif /*!_LIST_H_ */
