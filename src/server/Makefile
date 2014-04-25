##
## Makefile for ftp in /home/maxime/projet/actu/PSU_2013_myftp
## 
## Made by Maxime
## Login   <maxime@epitech.net>
## 
## Started on  Sat Mar 29 01:31:11 2014 Maxime
## Last update Fri Apr 25 13:55:59 2014 Etienne
##

SRC		= ./main.c		\
		  ./socket_serveur.c	\
		  ./init_data.c		\
		  ./add_client.c	\
		  ./list.c		\
		  ./str_to_wordtab.c	\
		  ./parse_and_exec.c	\
		  ./send.c		\
		  ./cmd_serv.c		\
		  ./read_client.c


OBJ		= $(SRC:.c=.o)

NAME		= ../../serveur

INCLUDE		= ./includes/

CFLAGS		= -W -Wall -Wextra -I$(INCLUDE) -g

INVOCATION	= cc

$(NAME):	$(OBJ)
		$(INVOCATION) -o $(NAME) $(CFLAGS) $(OBJ)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
