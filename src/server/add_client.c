/*
** add_client.c for add_client in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 14:49:58 2014 Etienne
** Last update Wed Apr 16 17:00:03 2014 Etienne
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
  new_client->id = serv->nb_client;
  serv->nb_client++;
  list_ptr_list(serv->client);
}
