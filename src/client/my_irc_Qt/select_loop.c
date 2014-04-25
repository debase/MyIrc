/*
** select_loop.c for select_loop in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/client/my_irc_Qt
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Tue Apr 22 21:42:55 2014 Etienne
** Last update Tue Apr 22 21:42:57 2014 Etienne
*/

#include <time.h>
#include "client.h"

static void        init_fd_set(t_client *client, struct timeval *tm)
{
    tm->tv_sec = 0;
    tm->tv_usec = 1000;
    FD_ZERO(&client->read_fds);
    FD_SET(client->sfd, &client->read_fds);
}

void                select_loop(t_client *client)
{
    int             select_ret;
    struct  timeval tm;

    select_ret= 0;
    if (client->connect == CONNECTED)
    {
        init_fd_set(client, &tm);
        select_ret = select(client->sfd + 1, &client->read_fds, NULL,
                            NULL, &tm);
        if (select_ret != -1)
        {
            if (FD_ISSET(client->sfd, &client->read_fds))
            {
                manage_client_rcv_msg(this->client);
            }
        }
        else
        {
            snprintf(client->logger, BUFF_SIZE, "Select error\n");
            return;
        }
    }
}
