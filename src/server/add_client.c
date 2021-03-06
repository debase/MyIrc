/*
** add_client.c for add_client in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 14:49:58 2014 Etienne
** Last update Sun Apr 27 19:29:55 2014 Etienne
*/

#include "serveur.h"
#include "list.h"

void		add_new_client(t_serveur *serv)
{
  int		clilen;
  t_client	*new_client;

  clilen = sizeof(struct sockaddr_in);
  new_client = push_back_list(&serv->client, sizeof(t_client));
  if (!new_client)
    {
      fprintf(stderr, "Error allocating memmory in function (%s)\n",
  	      __PRETTY_FUNCTION__);
      exit(EXIT_FAILURE);
    }
  new_client->cfd = accept(serv->fd, (struct sockaddr *)&new_client->cli_addr,
		       (socklen_t *)&clilen);
  if (new_client->cfd < 0)
    {
      fprintf(stderr, "Error : accept() failded in function (%s)\n",
  	      __PRETTY_FUNCTION__);
      exit(EXIT_FAILURE);
    }
  printf ("New client IP %s join the server\n",
	  inet_ntoa(new_client->cli_addr.sin_addr));
  new_client->id = serv->nb_client;
  snprintf(new_client->name, BUFF_SIZE, "user%d", new_client->id);
  serv->nb_client++;
  send_info_msg(new_client, "Welcome to IRC server :)");
}

void		rm_client(t_serveur *serv, t_client *client)
{
  t_client	*list;
  char		buff[BUFF_SIZE];

  list = serv->client;
  snprintf(buff, BUFF_SIZE, "%s quit the channel \"%s\"", client->name,
	   client->chan);
  if (client->chan[0])
    {
      while (list)
	{
	  if (!strcmp(client->chan, list->chan) && (list != client))
	    send_info_msg(list, buff);
	  list = list->next;
	}
    }
  serv->nb_client--;
  close(client->cfd);
  rm_elem_list(&serv->client, client);
}
