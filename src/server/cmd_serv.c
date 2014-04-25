/*
** cmd_serv.h<2> for cmd_serv in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Apr 25 13:46:10 2014 Etienne
** Last update Fri Apr 25 14:00:18 2014 Etienne
*/

#include "serveur.h"

void		join_channel(t_serveur *serv, t_client *client, char **cmd)
{
  char		buff[BUFF_SIZE];

  if (cmd[1] == NULL)
    {
      printf("invalid channel !\n");
      send_info_msg(client, "Invalid channel !\n");
    }
}
