/*
** main.c for irc in /home/maxime/projet/actu/PSU_2013_myirc
**
** Made by Maxime
** Login   <maxime@epitech.net>
**
** Started on  Tue Apr  8 16:50:26 2014 Maxime
** Last update Sun Apr 27 21:41:17 2014 Etienne
*/

#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include "serveur.h"
#include "str_to_wordtab.h"

void		set_fd_client(fd_set *readfd, t_serveur *serv)
{
  t_client	*tmp;

  serv->max_fd = serv->fd;
  tmp = serv->client;
  while (tmp)
    {
      FD_SET(tmp->cfd, readfd);
      if (tmp->cfd > serv->max_fd)
	serv->max_fd = tmp->cfd;
      tmp = tmp->next;
    }
}

void		check_client_fd(t_serveur *serv, fd_set *readfd)
{
  t_client	*tmp;
  t_client	*tmp2;

  tmp = serv->client;
  while (tmp)
    {
      if (FD_ISSET(tmp->cfd, readfd))
  	{
	  tmp2 = tmp->next;
	  read_client(serv, tmp);
	  tmp = tmp2;
  	}
      else
	{
	  tmp = tmp->next;
	}
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
      select_ret = select(serv->max_fd + 1, &readfd, NULL, NULL, NULL);
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
      printf("Uage : %s <Port>\n", argv[0]);
      return (EXIT_SUCCESS);
    }
  if (init_serveur(&serveur, argv[1]) != -1)
    {
      signal(SIGPIPE, SIG_IGN);
      serv_loop(&serveur);
    }
  return (EXIT_SUCCESS);
}
