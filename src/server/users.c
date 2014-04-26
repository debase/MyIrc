/*
** users.c for users in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Apr 26 18:01:40 2014 Etienne
** Last update Sat Apr 26 19:06:03 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

static int	users_loop(t_client *list, t_client *client)
{
  char		buff[BUFF_SIZE];
  int		nb_users;

  nb_users = 0;
  while (list)
    {
      if (!strcmp(list->chan, client->chan))
	{
	  snprintf(buff, BUFF_SIZE, list->name);
	  send_info_msg(client, buff);
	  nb_users++;
	}
      list = list->next;
    }
  return (nb_users);
}

void		list_users(t_serveur *serv, t_client *client,
			   __attribute__((unused))char **cmd,
			   __attribute__((unused))char *str)
{
  char		buff[BUFF_SIZE];
  int		nb_users;

  if (!client->chan[0])
    {
      snprintf(buff, BUFF_SIZE,
	       "You have to be connected to a channel to list users");
      send_info_msg(client, buff);
      return;
    }
  snprintf(buff, BUFF_SIZE, "Listing users on the current channel \"%s\" ...",
	   client->chan);
  send_info_msg(client, buff);
  nb_users = users_loop(serv->client, client);
  snprintf(buff, BUFF_SIZE, "%d users found on the channel", nb_users);
  send_info_msg(client, buff);
}
