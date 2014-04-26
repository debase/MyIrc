/*
** join_channel.c for join_channel.c in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Apr 26 03:53:04 2014 Etienne
** Last update Sat Apr 26 22:56:50 2014 Etienne
*/

#include <string.h>
#include "cmd_serv.h"
#include "serveur.h"

void		alert_join_channel(t_serveur *serv, t_client *client)
{
  t_client	*list;
  char		buff[BUFF_SIZE];
  int		bool;

  bool = 0;
  list = serv->client;
  snprintf(buff, BUFF_SIZE, "%s have join the channel", client->name);
  while (list)
    {
      if (!strcmp(client->chan, list->chan) && (list != client) && (bool = 1))
	send_info_msg(list, buff);
      list = list->next;
    }
  snprintf(buff, BUFF_SIZE,
	   (bool == 1 ? "You have successfully join the channel \"%s\""
	    : "You have successfully created the channel \"%s\""), client->chan);
  send_info_msg(client, buff);
}

void		join_channel(t_serveur *serv, t_client *client,
			     char **cmd, char *str)
{
  char		*cmd_part[2];

  if (cmd[1] == NULL)
    send_info_msg(client, "Invalid channel !");
  else if (!strcmp(client->chan, cmd[1]))
    send_info_msg(client, "You are already connected to this channel");
  else
    {
      if (client->chan[0])
	{
	  cmd_part[1] = client->chan;
	  part_channel(serv, client, cmd_part, str);
	}
      snprintf(client->chan, BUFF_SIZE, "%s", cmd[1]);
      alert_join_channel(serv, client);
    }
}
