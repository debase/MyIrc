/*
** serveur_socket.h for socket_serveur in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 16 10:17:18 2014 Etienne
** Last update Wed Apr 16 10:37:13 2014 Etienne
*/

#ifndef _SERVEUR_SOCKET_H_
# define _SERVEUR_SOCKET_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <unistd.h>
# include <netdb.h>

int		create_socket_server(const char *port);

#endif /* _SERVEUR_SOCKET_H_ */
