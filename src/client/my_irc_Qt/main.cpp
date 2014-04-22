#include <QApplication>
#include "ircdisplay.h"

void                init_client(t_client *client)
{
    memset(client, 0, sizeof(*client));
    client->connect = DISCONNECTED;
}

int                 main(int argc, char *argv[])
{
    QApplication    a(argc, argv);
    ircDisplay      *display;
    t_client        client;

    init_client(&client);
    display = new ircDisplay(&client);
    display->show();
    display->display();
    return (a.exec());
}
