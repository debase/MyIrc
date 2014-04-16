##
## Makefile for ftp in /home/maxime/projet/actu/PSU_2013_myftp
## 
## Made by Maxime
## Login   <maxime@epitech.net>
## 
## Started on  Sat Mar 29 01:31:11 2014 Maxime
## Last update Tue Apr 15 17:43:39 2014 Etienne
##

SRC		= ./main.c

OBJ		= $(SRC:.c=.o)

NAME		= ../../client

CFLAGS		= -W -Wall -Werror -Wextra

INVOCATION	= cc

$(NAME):	$(OBJ)
		$(INVOCATION) $(CFLAGS) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
