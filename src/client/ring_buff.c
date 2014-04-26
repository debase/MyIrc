/*
** ring_buff.c for ring_buff in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/client/my_irc_Qt
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Apr 25 14:36:35 2014 Etienne
** Last update Sun Apr 27 01:47:17 2014 Etienne
*/

#include <unistd.h>
#include <string.h>
#include "client.h"

static int		add_char_buff(t_ring_buff *ring_buff, char c)
{
  if ((ring_buff->end + 2) % BUFF_SIZE != 0)
    {
      ring_buff->buff[ring_buff->end] = c;
      ring_buff->end++;
    }
  else
  {
    ring_buff->buff[ring_buff->end] = '\n';
  }
    return (1);
}

static int	put_ring_buff(t_ring_buff *ring_buff, char *buff, ssize_t len)
{
  int		i;
  int		index;

  index = -1;
  i = 0;
  while (i < len && add_char_buff(ring_buff, buff[i]))
    {
      i++;
    }
  while (ring_buff->begin <= ring_buff->end)
    {
      if (ring_buff->buff[ring_buff->begin] == '\n')
	{
        index = ring_buff->begin;
    }
      ring_buff->begin++;
    }
  if (index != -1)
  {
      ring_buff->buff[index] = '\0';
      return (1);
  }
  return (0);
}

void		manage_client_rcv_msg(t_client *client)
{
  char		buff[BUFF_SIZE + 3];
  ssize_t	bufflen;

  memset(buff, 0, sizeof(buff));
  if ((bufflen = recv(client->sfd, buff, BUFF_SIZE, 0)) <= 0)
    {
      snprintf(client->logger, BUFF_SIZE,
               "Server [%s:%s] seem to be broken. You are now disconnected\n",
               client->host, client->port);
      client->connect = DISCONNECTED;
      close(client->sfd);
      return;
    }
  if (put_ring_buff(&client->rvcbuff, buff, bufflen))
    {
      client->rvcbuff.display = 1;
    }
}
