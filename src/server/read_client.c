/*
** read_client.c for read_client in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Thu Apr 24 13:30:33 2014 Etienne
** Last update Sat Apr 26 03:29:37 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

static int	add_char_buff(t_ring_buff *ring_buff, char c)
{
  if ((ring_buff->end + 1) % BUFF_SIZE != 0)
    {
      ring_buff->buff[ring_buff->end] = c;
      ring_buff->end++;
    }
  else
    ring_buff->buff[ring_buff->end] = '\n';
  return (1);
}

static int	put_ring_buff(t_ring_buff *ring_buff, char *buff, ssize_t len)
{
  int		i;

  i = 0;
  while (i < len && add_char_buff(ring_buff, buff[i]))
    {
      i++;
    }
  while (ring_buff->begin <= ring_buff->end)
    {
      if (ring_buff->buff[ring_buff->begin] == '\n')
	{
	  ring_buff->buff[ring_buff->begin] = '\0';
	  return (1);
	}
      ring_buff->begin++;
    }
  return (0);
}

void		read_client(t_serveur *serv, t_client *client)
{
  char		buff[BUFF_SIZE + 3];
  ssize_t	bufflen;

  memset(buff, 0, sizeof(buff));
  if ((bufflen = recv(client->cfd, buff, BUFF_SIZE, 0)) <= 0)
    {
      printf("Client %s with IP %s disconnect\n", client->name,
	     inet_ntoa(client->cli_addr.sin_addr));
      rm_client(serv, client);
      return;
    }
  if (put_ring_buff(&client->rcvbuff, buff, bufflen))
    {
      memset(buff, 0, sizeof(buff));
      strncpy(buff, client->rcvbuff.buff, sizeof(buff));
      memset(&client->rcvbuff, 0, sizeof(client->rcvbuff));
      parse_and_exec(buff, serv, client);
    }
}
