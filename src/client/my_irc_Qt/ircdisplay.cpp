#include "ircdisplay.h"
#include <QTimer>
#include <iostream>

ircDisplay::ircDisplay(t_client *client, QWidget *parent) : QWidget(parent)
{
    chat = new QTextEdit;
    sendButton = new QPushButton(tr("Send"));
    Vbox = new QVBoxLayout;
    textSender = new QTextEdit;

    textSender->setFixedHeight(40);
    chat->setReadOnly(true);
    Vbox->addWidget(chat);
    Vbox->addWidget(textSender);
    Vbox->addWidget(sendButton);

    chat->insertPlainText(QString("Hello and welcome to my QtIrc :)\n"));
    chat->insertPlainText(QString("Use /server <host> <port> to connect you\n"));
    chat->insertPlainText(QString("=========================================\n"));

    this->client = client;
    this->resize(600, 500);
    this->setLayout(Vbox);
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendDisplay()));
}

ircDisplay::~ircDisplay()
{
}

void                ircDisplay::display_msg(char *msg)
{
    chat->insertPlainText(QString(msg));
}

void                ircDisplay::sendDisplay()
{
    const char      *data;
    std::string     cmd;

    if (this->textSender->toPlainText().size() != 0)
    {
       cmd = this->textSender->toPlainText().toStdString();
       std::cout << cmd << std::endl;
       send_msg(this->client, strdup(cmd.c_str()));
       if (client->logger[0])
       {
           chat->insertPlainText(client->logger);
           memset(client->logger, 0, BUFF_SIZE);
       }
       //std::cout << "toto" << std::endl;
       this->textSender->clear();
    }
}

void        ircDisplay::display()
{
    int     select_ret;
    
    select_ret= 0;
    if (client->connect == CONNECTED)
    {
        FD_ZERO(&client->read_fds);
        FD_ZERO(&client->write_fds);
        FD_SET(client->sfd, &client->read_fds);
        FD_SET(client->sfd, &client->write_fds);
        select_ret = select(4, &client->read_fds, &client->write_fds,
                       NULL, NULL);
        if (select_ret != -1)
        {
            if (FD_ISSET(client->sfd, &client->read_fds))
            {
//                manage_client_rcv_msg(this->client);
            }
            if (FD_ISSET(client->sfd, &client->write_fds))
            {
//                manage_client_send_msg(this->client);
            }
        }
        else
        {
        }
    }
   QTimer::singleShot(5000, this, SLOT(display()));
}
