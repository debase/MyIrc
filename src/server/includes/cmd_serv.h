/*
** cmd_serv.h for cmd_serv in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Apr 25 13:45:00 2014 Etienne
** Last update Sat Apr 26 19:16:45 2014 Etienne
*/

#ifndef _CMD_SERV_H_
# define _CMD_SERV_H_

#include "serveur.h"

void		join_channel(t_serveur *, t_client *, char **, char *);
void		change_nick(t_serveur *, t_client *, char **, char *);
void		list_channel(t_serveur *, t_client *, char **, char *);
void		part_channel(t_serveur *, t_client *, char **, char *);
void		list_users(t_serveur *, t_client *, char **, char *);
void		pv_msg(t_serveur *, t_client *, char **, char *);


#endif /* !_CMD_SERV_H_ */
