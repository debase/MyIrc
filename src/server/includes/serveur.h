/*
** serveur.h for serveur in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 09:42:28 2014 Etienne
** Last update Sat Apr 26 03:33:59 2014 Etienne
*/

#ifndef _SERVEUR_H_
# define _SERVEUR_H_

# include <netinet/in.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define	MAX_CLIENT	100
# define	BUFF_SIZE	4096

typedef struct	s_ring_buff
{
  char		buff[BUFF_SIZE];
  int		end;
  int		begin;
}		t_ring_buff;

typedef struct		s_client
{
  int			cfd;
  struct sockaddr_in	cli_addr;
  t_ring_buff		rcvbuff;
  int			id;
  char			name[BUFF_SIZE];
  char			chan[BUFF_SIZE];
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef	struct	s_serveur
{
  int		fd;
  t_client	*client;
  int		nb_client;
  int		max_fd;
}		t_serveur;


typedef struct	s_func_ptr
{
  char		*str;
  void		(*ptr)(t_serveur *, t_client *client, char **cmd);
}		t_func_ptr;

int		init_serveur(t_serveur *serv, char *port);
void		add_new_client(t_serveur *serv);
void		read_client(t_serveur *serv, t_client *client);
void		rm_client(t_serveur *serv, t_client *client);
void		parse_and_exec(char *buff, t_serveur *serv, t_client *client);
void            send_to_channel(t_serveur *serv, t_client *from, char *msg);
void            send_pv_msg(t_client *from, t_client *to, char *msg);
void            send_basic_msg(t_client *from, t_client *to, char *msg);
void            send_info_msg(t_client *to, char *msg);
void            send_to_other_channel(t_serveur *serv, t_client *from,
				      char *msg);
void		change_nick(t_serveur *serv, t_client *client, char **cmd);
void		list_channel(t_serveur *serv, t_client *client, char **cmd);
void		part_channel(t_serveur *serv, t_client *client, char **cmd);

#endif /* !_SERVEUR_H_ */
