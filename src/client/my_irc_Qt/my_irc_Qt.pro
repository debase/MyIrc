#-------------------------------------------------
#
# Project created by QtCreator 2014-04-16T19:43:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my_irc_Qt
TEMPLATE = app


SOURCES += main.cpp\
        ircdisplay.cpp \
    client_manage_msg.c \
    socket_client.c \
    connect.c \
    select_loop.c \
    str_to_wordtab.c \
    ring_buff.c

CXXFLAGS += -g
CFLAGS += -g

INCLUDEPATH += ../includes

HEADERS  += ircdisplay.h \
    ../includes/client.h \
    ../includes/str_to_wordtab.h
