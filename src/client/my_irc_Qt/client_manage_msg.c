/*
** client_manage_msg.c for manage_msg in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/client/my_irc_Qt
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Thu Apr 17 00:07:25 2014 Etienne
** Last update Mon Apr 21 16:56:09 2014 Etienne
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "client.h"
#include "str_to_wordtab.h"

void		send_msg(t_client *client, char *cmd)
{
  client->cmd = str_to_wordtab(cmd, " \t");
  if (!client->cmd[0])
    return;
  if (!strcmp(client->cmd[0], "/server") && client->connect != CONNECTED)
    {
      if (client->cmd[1])
          client->cmd[1][strlen(client->cmd[1]) - 1] = '\0';
      connect_client(client, client->cmd[1]);
    }
  else if (client->connect == CONNECTED)
  {
      if (send(client->sfd, cmd, strlen(cmd), 0) <= 0)
      {
          printf("toto\n");
          snprintf(client->logger, BUFF_SIZE,
                   "Server seem being broken ... You are now disconnect\n");
          client->connect = DISCONNECTED;
          close(client->sfd);
      }
  }
  else
    snprintf(client->logger, BUFF_SIZE, "You are not connected"
         " : Use /server <host> <port> to connect you\n");
}
