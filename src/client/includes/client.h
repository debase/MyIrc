/*
** client.h for client in /home/debas_e/Project/System_Unix/PSU_2013_myftp
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr  8 14:12:36 2014 Etienne
** Last update Sun Apr 27 19:26:04 2014 Etienne
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <stdio.h>
# include <sys/select.h>

# define CONNECTED      1
# define DISCONNECTED   2
# define BUFF_SIZE      4096
# define DEFAULT_PORT   "6000"
# define ALLOC_ERR_MSG  "Allocation error\n"

typedef struct  s_ring_buff
{
    char        buff[BUFF_SIZE + 1];
    char        cur_msg[BUFF_SIZE + 1];
    int         begin;
    int         end;
    int         display;
}               t_ring_buff;

typedef struct  s_client
{
    int         sfd;
    int         connect;
    char        **cmd;
    char        logger[BUFF_SIZE + 1];
    fd_set      read_fds;
    char        *host;
    char        *port;
    t_ring_buff rvcbuff;
}               t_client;

int		create_socket_client(const char *host, const char *port);
void		send_msg(struct s_client *client, char *cmd);
void		connect_client(t_client *client, char *param);
void		select_loop(t_client *client);
void		manage_client_rcv_msg(t_client *client);

#endif /* !_CLIENT_H_ */
