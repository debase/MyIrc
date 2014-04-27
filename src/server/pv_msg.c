/*
** pv_msg.c for pv_msg in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sat Apr 26 18:53:10 2014 Etienne
** Last update Sun Apr 27 19:30:59 2014 Etienne
*/

#include <string.h>
#include "serveur.h"

static void	epur_msg(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    if (str[i] != ' ' && str[i] != '\t')
      str[j++] = str[i++];
    else
      {
	str[j++] = ' ';
        while (str[i] == ' ' || str[i] == '\t')
          i++;
      }
  str[j] = 0;
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
}

static t_client	*find_user(t_client *list, t_client *client,
			   char *user, char *buff)
{
  if (!strcmp(user, client->name))
    {
      snprintf(buff, BUFF_SIZE,
	       "Sending msg to oneself is a little bit retarded ...");
      return (NULL);
    }
  while (list)
    {
      if (!strcmp(list->chan, client->chan) && !strcmp(list->name, user))
	return (list);
      list = list->next;
    }
  snprintf(buff, BUFF_SIZE,
	   "Can't found user \"%s\" on the channel ...", user);
  return (NULL);
}

void		pv_msg(t_serveur *serv, t_client *client,
		       char **cmd, char *str)
{
  char		buff[BUFF_SIZE];
  t_client	*client_to;

  if (!cmd[1] || !cmd[2])
    {
      snprintf(buff, BUFF_SIZE, "Invalid format command : /msg users msg");
      send_info_msg(client, buff);
    }
  else
    {
      if ((client_to = find_user(serv->client, client, cmd[1], buff)) == NULL)
	return (send_info_msg(client, buff));
      epur_msg(str);
      snprintf(buff, BUFF_SIZE, "%s",
	       str + strlen(cmd[0]) + strlen(cmd[1]) + 2);
      send_pv_msg(client, client_to, buff);
      send_pv_msg(client, client, buff);
    }
}
