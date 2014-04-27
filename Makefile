##
## Makefile for Makefile in /tmp/PSU_2013_myirc
## 
## Made by Etienne
## Login   <debas_e@epitech.net>
## 
## Started on  Sun Apr 27 01:59:22 2014 Etienne
## Last update Sun Apr 27 02:01:12 2014 Etienne
##

NAME    = My_Irc

PATHS   = src/server \
          src/client

$(NAME):
	@for dir in $(PATHS); do \
	echo -e "\e[30m [\e[34mCompiling: \e[31m$$dir\e[30m]\e[0m"; make --no-print-directory -C $$dir; \
	done

all: $(NAME)

clean:
	@for dir in $(PATHS); do \
	echo -e "\e[30m [\e[34mCleaning: \e[31m$$dir\e[30m]\e[0m"; make --no-print-directory -C $$dir clean; \
	done

fclean:
	@for dir in $(PATHS); do \
	echo -e "\e[30m [\e[34mRemoving: \e[31m$$dir\e[30m]\e[0m"; make --no-print-directory -C $$dir fclean; \
	done

re:     fclean all

.PHONY: $(NAME) all clean fclean re
