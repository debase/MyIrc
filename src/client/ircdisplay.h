#ifndef IRCDISPLAY_H
#define IRCDISPLAY_H

#include <QWidget>
#include <QLineEdit>
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
    virtual ~ircDisplay();
    void    display_msg(char *msg);
    void    keyPressEvent(QKeyEvent *event);
public slots:
    void    loop();
    void    sendDisplay();
private:
    QLineEdit       *textSender;
    QTextEdit       *chat;
    QPushButton     *sendButton;
    QVBoxLayout     *Vbox;
    t_client        *client;
};

#endif // IRCDISPLAY_H
