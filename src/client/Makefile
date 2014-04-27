##
## Makefile for Makefile in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/client/my_irc_Qt
## 
## Made by Etienne
## Login   <debas_e@epitech.net>
## 
## Started on  Sat Apr 26 21:11:20 2014 Etienne
## Last update Sun Apr 27 19:39:36 2014 Etienne
##

NAME		= ../../client

CC		= gcc

CXX		= g++

CFLAGS        	= -Wall -Wall -Wextra

CXXFLAGS      	= -Wall -Wall -Wextra

LIBS		= -L/usr/lib64 -lQtGui -L/usr/X11R6/lib -lQtCore -lpthread

CXXINCPATH     	= -I/usr/share/qt4/mkspecs/default -I/usr/include/QtCore
CXXINCPATH     	+= -I/usr/include/QtGui -I/usr/include -I./includes -I.

CINCPATH     	= -I./includes/

SOURCES       	= main.cpp \
		  ircdisplay.cpp \
		  moc_ircdisplay.cpp \
		  client_manage_msg.c \
		  socket_client.c \
		  connect.c \
		  select_loop.c \
		  str_to_wordtab.c \
		  ring_buff.c

OBJECTS       	= main.o \
		  moc_ircdisplay.o \
		  ircdisplay.o \
		  client_manage_msg.o \
		  socket_client.o \
		  connect.o \
		  select_loop.o \
		  str_to_wordtab.o \
		  ring_buff.o

LINK		= g++

$(NAME): $(OBJECTS)
	$(LINK) -o $(NAME) $(OBJECTS) $(LIBS)

all:	$(NAME)

main.o: main.cpp ./includes/ircdisplay.h
	$(CXX) -c $(CXXFLAGS) $(CXXINCPATH) -o main.o main.cpp

ircdisplay.o: ircdisplay.cpp ./includes/ircdisplay.h
	$(CXX) -c $(CXXFLAGS) $(CXXINCPATH) -o ircdisplay.o ircdisplay.cpp

moc_ircdisplay.o: moc_ircdisplay.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXINCPATH) -o moc_ircdisplay.o moc_ircdisplay.cpp

client_manage_msg.o: client_manage_msg.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o client_manage_msg.o client_manage_msg.c

socket_client.o: socket_client.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o socket_client.o socket_client.c

connect.o: connect.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o connect.o connect.c

select_loop.o: select_loop.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o select_loop.o select_loop.c

str_to_wordtab.o: str_to_wordtab.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o str_to_wordtab.o str_to_wordtab.c

ring_buff.o: ring_buff.c
	$(CC) -c $(CFLAGS) $(CINCPATH) -o ring_buff.o ring_buff.c

clean:
	$(RM) $(OBJECTS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

