##
## Makefile for ftp in /home/maxime/projet/actu/PSU_2013_myftp
## 
## Made by Maxime
## Login   <maxime@epitech.net>
## 
## Started on  Sat Mar 29 01:31:11 2014 Maxime
## Last update Wed Apr 16 21:18:21 2014 Etienne
##

SRC		= ./main.c		\
		  ./socket_client.c

OBJ		= $(SRC:.c=.o)

NAME		= ../../client

INCDIR		= ./includes

CFLAGS		= -W -Wall -Werror -Wextra -I$(INCDIR)

INVOCATION	= cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
