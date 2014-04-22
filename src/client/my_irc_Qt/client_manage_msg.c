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
#include "client.h"

char        **to_word_tab(char *str, char *cmd[], int size, const char *token)
{
  char    *save;
  int     index;

  index = 0;
  if (!str)
    {
      return (NULL);
    }
  while ((index < (size - 1)) && (cmd[index] = strtok_r((index == 0 ? str : NULL),
							token, &save)) != NULL)
    {
      index++;
    }
  cmd[index] = NULL;
  return (cmd);
}

void		send_msg(t_client *client, char *cmd)
{
  int		index;

  index = 0;
  to_word_tab(cmd, client->cmd, 5, " \t");
  if (!client->cmd[0])
    return;
  if (!strcmp(client->cmd[0], "/server") && client->connect != CONNECTED)
    {
      connect_client(client, client->cmd[1]);
    }
  else if (client->connect == CONNECTED)
    {
      //        put_msg_in_buff();
    }
  else
    snprintf(client->logger, BUFF_SIZE, "You are not connected"
         " : Use /server <host> <port> to connect you\n");
}
