##
## Makefile for ftp in /home/maxime/projet/actu/PSU_2013_myftp
## 
## Made by Maxime
## Login   <maxime@epitech.net>
## 
## Started on  Sat Mar 29 01:31:11 2014 Maxime
## Last update Sat Apr 26 22:24:41 2014 Etienne
##

NAME		= ../../serveur

INCLUDE		= ./includes/

CFLAGS		= -W -Wall -Wextra -I$(INCLUDE)

CC		= gcc

RM		= rm -rf

SRCS		= ./main.c		\
		  ./socket_serveur.c	\
		  ./init_data.c		\
		  ./add_client.c	\
		  ./list.c		\
		  ./str_to_wordtab.c	\
		  ./parse_and_exec.c	\
		  ./send.c		\
		  ./cmd_serv.c		\
		  ./part_channel.c	\
		  ./join_channel.c	\
		  ./list_channel.c	\
		  ./users.c		\
		  ./pv_msg.c		\
		  ./read_client.c

OBJS		= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
