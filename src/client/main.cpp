#include <QApplication>
#include <signal.h>
#include "ircdisplay.h"

void		init_client(t_client *client)
{
  memset(client, 0, sizeof(*client));
  client->connect = DISCONNECTED;
}

int			main(int argc, char *argv[])
{
  QApplication	a(argc, argv);
  ircDisplay		*display;
  t_client		client;

  init_client(&client);
  display = new ircDisplay(&client);
  signal(SIGPIPE, SIG_IGN);
  display->show();
  display->loop();
  return (a.exec());
}
