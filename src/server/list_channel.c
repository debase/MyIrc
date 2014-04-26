/*
** list_channel.c for list_channel in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Apr 26 03:53:48 2014 Etienne
** Last update Sat Apr 26 03:54:10 2014 Etienne
*/

#define _GNU_SOURCE
#include <string.h>
#include "serveur.h"

static int	already_list(t_serveur *serv, t_client *client)
{
  t_client	*list;

  list = serv->client;
  while (list != client)
    {
      if (!strcmp(list->chan, client->chan))
	{
	  return (1);
	}
      list = list->next;
    }
  return (0);
}

void		list_channel(t_serveur *serv,
			     __attribute__((unused))t_client *client,
			     char **cmd)
{
  t_client	*list;
  char		buff[BUFF_SIZE];
  int		nb_chan;

  nb_chan = 0;
  list = serv->client;
  if (cmd[1])
    snprintf(buff, BUFF_SIZE, "Listing channel on the server with [%s]",
	     cmd[1]);
  else
    snprintf(buff, BUFF_SIZE, "Listing all channel on the server");
  send_info_msg(client, buff);
  while (list)
    {
      if (list->chan[0] && !already_list(serv, list)
	  && (cmd[1] == NULL || strcasestr(list->chan, cmd[1])))
	{
	  send_info_msg(client, list->chan);
	  nb_chan++;
	}
      list = list->next;
    }
  snprintf(buff, BUFF_SIZE, "found %d channel on the server", nb_chan);
  send_info_msg(client, buff);
}
