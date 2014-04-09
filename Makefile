##
## Makefile for ftp in /home/maxime/projet/actu/PSU_2013_myftp
## 
## Made by Maxime
## Login   <maxime@epitech.net>
## 
## Started on  Sat Mar 29 01:31:11 2014 Maxime
## Last update Wed Apr  9 10:28:53 2014 Maxime
##

NAME=		serveur/client

SUB_DIR=	src/server \
		src/client

$(NAME)	:
		@for dir in $(SUB_DIR); do \
		make -C $$dir all; \
		done

all:		$(NAME)

clean:
		@for dir in $(SUB_DIR); do \
		make -C $$dir clean; \
		done

fclean:
		@for dir in $(SUB_DIR); do \
		make -C $$dir fclean; \
		done

re:		fclean	all

.PHONY: $(NAME) all clean fclean re
