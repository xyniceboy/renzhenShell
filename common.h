#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <curses.h>
#include <term.h>

extern char **environ;

#define  MAXARGS	20	/* cmdline args*/
#define PROMPT_LEN	256	/*	token lenght*/

extern char prompt[PROMPT_LEN];

extern void set_prompt(char *);
extern void cmd_to_argv(char *, char **);
extern void do_cd(char *argv[]);

#endif
