#ifndef IRCDISPLAY_H
#define IRCDISPLAY_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
extern "C"
{
    #include "client.h"
}

class ircDisplay : public QWidget
{
    Q_OBJECT

public:
    ircDisplay(t_client *client, QWidget *parent = 0);
    ~ircDisplay();
public slots:
    void    display_msg(char *msg);
    void    sendDisplay();
    void    display();
private:
    QTextEdit       *textSender;
    QTextEdit       *chat;
    QPushButton     *sendButton;
    QVBoxLayout     *Vbox;
    t_client        *client;
};

#endif // IRCDISPLAY_H
