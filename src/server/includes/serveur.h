/*
** serveur.h for serveur in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 09:42:28 2014 Etienne
** Last update Wed Apr 16 16:23:57 2014 Etienne
*/

#ifndef _SERVEUR_H_
# define _SERVEUR_H_

# include <netinet/in.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define	MAX_CLIENT	100
# define	BUFF_SIZE	4096

typedef struct	s_circle_buff
{
  char		buff[BUFF_SIZE];
  int		end;
  int		curlen;
}		t_circle_buff;

typedef struct		s_client
{
  int			cfd;
  struct sockaddr_in	cli_addr;
  t_circle_buff		buff;
  int			id;
  char			name[BUFF_SIZE];
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef	struct	s_serveur
{
  int		fd;
  t_client	*client;
  int		nb_client;
}		t_serveur;

int		init_serveur(t_serveur *serv, char *port);
void		add_new_client(t_serveur *serv);

#endif /* !_SERVEUR_H_ */
