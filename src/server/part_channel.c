/*
** channel.c for channel in /home/debas_e/Project/System_Unix/PSU_2013_myirc
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Apr 25 21:01:12 2014 Etienne
** Last update Sat Apr 26 19:05:37 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

static void	error_part_channel(t_client *client, char *chan)
{
  char		buff[BUFF_SIZE];

  if (!client->chan[0])
    snprintf(buff, BUFF_SIZE, "You are not connected to any channel");
  else if (chan == NULL)
    snprintf(buff, BUFF_SIZE, "Invalid channel");
  else
    {
      snprintf(buff, BUFF_SIZE,
	       "You are not connected to the channel \"%s\"", chan);
    }
  send_info_msg(client, buff);
}

void		part_channel(t_serveur *serv, t_client *client,
			     char **cmd, __attribute__((unused))char *str)
{
  t_client	*list;
  char		buff[BUFF_SIZE];

  if (cmd[1] == NULL || strcmp(cmd[1], client->chan) || !client->chan[0])
    {
      error_part_channel(client, cmd[1]);
      return;
    }
  list = serv->client;
  snprintf(buff, BUFF_SIZE, "%s have quit the channel \"%s\"",
	   client->name, client->chan);
  while (list)
    {
      if (!strcmp(client->chan, list->chan) && (list != client))
	send_info_msg(list, buff);
      list = list->next;
    }
  snprintf(buff, BUFF_SIZE, "You have successfully quit the channel \"%s\"",
	   client->chan);
  send_info_msg(client, buff);
  memset(client->chan, 0, sizeof(client->chan));
}
