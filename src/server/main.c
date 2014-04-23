/*
** main.c for irc in /home/maxime/projet/actu/PSU_2013_myirc
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Tue Apr  8 16:50:26 2014 Maxime
** Last update Wed Apr 23 10:09:49 2014 Etienne
*/

#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include "serveur.h"

int		usage(char *pname)
{
  printf("Uage : %s <Port>\n", pname);
  return (EXIT_SUCCESS);
}

void		set_fd_client(fd_set *readfd, t_serveur *serv)
{
  t_client	*tmp;

  tmp = serv->client;
  while (tmp)
    {
      FD_SET(tmp->cfd, readfd);
      tmp = tmp->next;
    }
}

void		check_client_fd(t_serveur *serv, fd_set *readfd)
{
  t_client	*tmp;
  char		buff[4096];

  tmp = serv->client;
  while (tmp)
    {
      if (FD_ISSET(tmp->cfd, readfd))
  	{
	  recv(tmp->cfd, buff, 4096, 0);
	  printf ("rcv : %s\n", buff);
  	}
      tmp = tmp->next;
    }
}

void			serv_loop(t_serveur *serv)
{
  fd_set		readfd;
  int			select_ret;

  select_ret = 0;
  while (select_ret != -1)
    {
      FD_ZERO(&readfd);
      FD_SET(serv->fd, &readfd);
      set_fd_client(&readfd, serv);
      select_ret = select(serv->nb_client + 4, &readfd, NULL, NULL, NULL);
      if (select_ret != -1)
	{
	  if (FD_ISSET(serv->fd, &readfd))
	    add_new_client(serv);
	  else
	    check_client_fd(serv, &readfd);
	}
      else
	fprintf(stderr, "select error : %s\n", strerror(errno));
    }
}

int		main(int ac, char *argv[])
{
  t_serveur	serveur;

  if (ac != 2)
    {
      return (usage(argv[0]));
    }
  if (init_serveur(&serveur, argv[1]) != -1)
    {
      serv_loop(&serveur);
    }
  return (EXIT_SUCCESS);
}
