/*
** send.c for send in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Thu Apr 24 22:12:51 2014 Etienne
** Last update Sat Apr 26 23:16:41 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

void		send_basic_msg(t_client *from, t_client *to, char *msg)
{
  char		buff[BUFF_SIZE];

  snprintf(buff, BUFF_SIZE, "%s : %s\n", from->name, msg);
  if (send(to->cfd, buff, strlen(buff), 0) <= 0)
    {
      fprintf(stderr, "Error sending msg to %s (%s)\n", to->name,
	      inet_ntoa(to->cli_addr.sin_addr));
    }
}

void		send_info_msg(t_client *to, char *msg)
{
  char		buff[BUFF_SIZE];

  snprintf(buff, BUFF_SIZE, "%s\n", msg);
  if (send(to->cfd, buff, strlen(buff), 0) <= 0)
    {
      fprintf(stderr, "Error sending msg to %s (%s)\n", to->name,
	      inet_ntoa(to->cli_addr.sin_addr));
    }
}

void		send_pv_msg(t_client *from, t_client *to, char *msg)
{
  char		buff[BUFF_SIZE];

  snprintf(buff, BUFF_SIZE, "[PV] %s : %s\n", from->name, msg);
  if (send(to->cfd, buff, strlen(buff), 0) <= 0)
    {
      fprintf(stderr, "Error sending msg to %s (%s)\n", to->name,
	      inet_ntoa(to->cli_addr.sin_addr));
    }
}

void		send_to_channel(t_serveur *serv, t_client *from, char *msg)
{
  t_client	*list;

  list = serv->client;
  while (list)
    {
      if (!strcmp(from->chan, list->chan))
	send_basic_msg(from, list, msg);
      list = list->next;
    }
}

void		send_to_other_channel(t_serveur *serv, t_client *from,
				      char *msg)
{
  t_client	*list;

  list = serv->client;
  while (list)
    {
      if (!strcmp(from->chan, list->chan) && (list->cfd != from->cfd))
	send_basic_msg(from, list, msg);
      list = list->next;
    }
}
