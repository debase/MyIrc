#include "ircdisplay.h"
#include <QTimer>
#include <iostream>

ircDisplay::ircDisplay(t_client *client, QWidget *parent) : QWidget(parent)
{
    chat = new QTextEdit;
    sendButton = new QPushButton(tr("Send"));
    Vbox = new QVBoxLayout;
    textSender = new QLineEdit;

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

void                ircDisplay::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        sendDisplay();
    }
}

void                ircDisplay::display_msg(char *msg)
{
    chat->insertPlainText(QString(msg));
}

void                ircDisplay::sendDisplay()
{
    char            *data;
    std::string     cmd;

    if (this->textSender->text().size() != 0)
    {
       cmd = this->textSender->text().toStdString();
       std::cout << cmd << std::endl;
       data = strdup(cmd.c_str());
       if (data != NULL)
           send_msg(this->client, data);
       else
           snprintf(client->logger, BUFF_SIZE, ALLOC_ERR_MSG);
       if (client->logger[0])
       {
           chat->insertPlainText("--->  " + QString(client->logger));
           memset(client->logger, 0, BUFF_SIZE);
       }
       this->textSender->clear();
    }
}

void        ircDisplay::loop()
{
    select_loop(this->client);
    QTimer::singleShot(5000, this, SLOT(loop()));
}
