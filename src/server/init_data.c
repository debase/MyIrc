/*
** init_data.c for init in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 10:41:37 2014 Etienne
** Last update Wed Apr 16 12:40:37 2014 Etienne
*/

#include "serveur.h"
#include "serveur_socket.h"

int		init_serveur(t_serveur *serv, char *port)
{
  int		port_number;

  port_number = atoi(port);
  if (!(port_number > 0 && port_number < 65535))
    {
      fprintf(stderr, "Error : port %s is invalid\n", port);
      return (-1);
    }
  serv->client = NULL;
  serv->nb_client = 0;
  serv->fd = create_socket_server(port);
  if (serv->fd < 0)
    {
      fprintf(stderr, "Error while creating server socket\n");
      return (-1);
    }
  if (listen(serv->fd, 40) < 0)
    {
      perror("listen");
      return (-1);
    }
  return (0);
}
