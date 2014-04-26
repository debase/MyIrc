/*
** connect.c for connect in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/client/my_irc_Qt
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Mon Apr 21 16:44:42 2014 Etienne
** Last update Sun Apr 27 00:59:13 2014 Etienne
*/

#include "client.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

char        *parse_host(t_client *client, char *str)
{
  int     index;
  char    *host;

  index = 0;
  while (str[index])
    {
      if (str[index] == ':')
	break;
      index++;
    }
  if (index == 0)
    {
      snprintf(client->logger, BUFF_SIZE, "Missing host to connect you\n");
      return (NULL);
    }
  if ((host = strndup(str, index)) == NULL)
    {
      snprintf(client->logger, BUFF_SIZE, "Allocation Error\n");
      return (NULL);
    }
  host[index] = '\0';
  return (host);
}

char        *parse_port(t_client *client, char *str)
{
  int     i;
  char    *occurence;
  char    *port;

  i = 0;
  occurence = index(str, ':');
  if (occurence == NULL || *(occurence + 1) == 0)
    occurence = DEFAULT_PORT;
  else
    occurence += 1;
  if ((port = strdup(occurence)) == NULL)
    {
      snprintf(client->logger, BUFF_SIZE, "Allocation Error\n");
      return (NULL);
    }
  while (port[i])
    {
      if (port[i] < '0' || port[i] > '9')
        {
	  snprintf(client->logger, BUFF_SIZE, "Invalid port\n");
	  return (NULL);
        }
      i++;
    }
  return (port);
}

int         check_host_port(t_client *client)
{
  int     invalid;

  invalid = 0;
  if (client->host == NULL || client->port == NULL)
    {
      invalid = 1;
    }
  else if (atoi(client->port) < 0 || atoi(client->port) > 65535)
    {
      snprintf(client->logger, BUFF_SIZE, "Invalid port : 0 < port < 65535\n");
      invalid = 1;
    }
  if (invalid)
    {
      if (client->host != NULL)
	free(client->host);
      if (client->port != NULL)
	free(client->port);
    }
  return (invalid);
}

void         connect_client(t_client *client, char *param)
{
  client->host = NULL;
  client->port = NULL;
  if (param == NULL)
    {
      snprintf(client->logger, BUFF_SIZE, "missing host[:port]\n");
      return;
    }
  client->host = parse_host(client, param);
  client->port = parse_port(client, param);
  if (check_host_port(client) == 1)
    return;
  printf ("Trying to connect to %s:%s\n", client->host, client->port);
  client->sfd = create_socket_client(client->host, client->port);
  if (client->sfd < 0)
    {
      snprintf(client->logger, BUFF_SIZE, "Error : couldn't connect to %s:%s\n",
	       client->host, client->port);
    }
  else
    {
      client->connect = CONNECTED;
    }
}
