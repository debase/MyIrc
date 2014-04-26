/*
** cmd_serv.h<2> for cmd_serv in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Apr 25 13:46:10 2014 Etienne
** Last update Sat Apr 26 02:21:21 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

static int	search_already_exist(t_serveur *serv, char *nick)
{
  t_client	*list;

  list = serv->client;
  while (list)
    {
      if (!strcmp(list->name, nick))
	{
	  return (1);
	}
      list = list->next;
    }
  return (0);
}

void		change_nick(t_serveur *serv, t_client *client, char **cmd)
{
  char		buff[BUFF_SIZE];
  t_client	*list;

  list = serv->client;
  if (cmd[1] == NULL)
    send_info_msg(client, "Invalid nickname");
  else if (search_already_exist(serv, cmd[1]))
    send_info_msg(client, "This nickaname already exist on this channel ...");
  else
    {
      snprintf(buff, BUFF_SIZE, "%s change is nickname to %s",
	       client->name, cmd[1]);
      while (list)
	{
	  if (!strcmp(list->chan, client->chan) && list != client)
	    send_info_msg(list, buff);
	  list = list->next;
	}
      snprintf(client->name, BUFF_SIZE, "%s", cmd[1]);
      snprintf(buff, BUFF_SIZE, "Successfully change nick to \"%s\"", cmd[1]);
      send_info_msg(client, buff);
    }
}
