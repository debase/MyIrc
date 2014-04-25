/*
** str_to_wordtab.h for str_to_wordtab in /home/debas_e/Project/System_Unix/PSU_2013_myirc/src/server
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Wed Apr 23 14:24:03 2014 Etienne
** Last update Wed Apr 23 16:16:29 2014 Etienne
*/

#ifndef _STR_TO_WORDTAB_H_
# define _STR_TO_WORDTAB_H_

# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define STR_WORD_TAB_ERROR      ((void *)-1)

char            **str_to_wordtab(char *str, char *token);

#endif /* !_STR_TO_WORDTAB_H_ */
