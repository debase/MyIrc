/*
** parse_and_exec.c for parse_and_exec in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Thu Apr 24 21:17:52 2014 Etienne
** Last update Sat Apr 26 04:02:53 2014 Etienne
*/

#include "serveur.h"
#include "cmd_serv.h"
#include "str_to_wordtab.h"

t_func_ptr	g_cmd[] =
  {
    {"/join", join_channel},
    {"/nick", change_nick},
    {"/list", list_channel},
    {"/part", part_channel},
    {NULL, NULL}
  };

static void	free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	free(tab[i++]);
      free(tab);
    }
}

void		parse_and_exec(char *str, t_serveur *serv, t_client *client)
{
  char		**cmd;
  int		i;

  i = 0;
  cmd = str_to_wordtab(str, " \t");
  if (cmd == STR_WORD_TAB_ERROR)
    return (send_info_msg(client, "! Internal server error occured !"));
  if (cmd && cmd[0])
    while (g_cmd[i].str)
      {
	if (!strcmp(g_cmd[i].str, cmd[0]))
	  {
	    g_cmd[i].ptr(serv, client, cmd);
	    free_tab(cmd);
	    return ;
	  }
	i++;
      }
  if (client->chan[0])
    send_to_channel(serv, client, str);
  else
    send_info_msg(client, "You need to be connected to a channel to send msg");
  free_tab(cmd);
}
