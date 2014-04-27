/*
** ircdisplay.h for irc_display in /tmp/PSU_2013_myirc/src/client/includes
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sun Apr 27 19:25:11 2014 Etienne
** Last update Sun Apr 27 19:25:42 2014 Etienne
*/

#ifndef IRCDISPLAY_H
# define IRCDISPLAY_H

# include <QWidget>
# include <QLineEdit>
# include <QPlainTextEdit>
# include <QPushButton>
# include <QVBoxLayout>

extern "C"
{
# include "client.h"
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

#endif /* !IRCDISPLAY_H */
