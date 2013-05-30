/*FILE: mysh.c 
 *VERSION: 1.0
 *FUNC:
 *  1.excute command on disk.
 *	2.implement a few builtin command, such as exit, cd.
 *	3.simple prompt.
 *AUTHOR: Ren Zhen
 *DATA:2013/5/4
 *
 */

#include "common.h"
#include "builtin.h"

void do_cmd(char *argv[]);

int main(void){
	char *arglist[MAXARGS+1];
	char *cmdline;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	
	while(1)
	{
		set_prompt(prompt);		
		
		if((cmdline = readline(prompt)) == NULL){
			continue;
		}


		cmd_to_argv(cmdline, arglist);

		if(strcmp(arglist[0], "exit") == 0){
			exit(EXIT_SUCCESS);
		}else if(strcmp(arglist[0], "cd") == 0){
			do_cd(arglist);
		}else{
			do_cmd(arglist);			/* do it*/
		}
	}

	return 0;
}


void do_cmd(char *argv[]){
	pid_t f_pid;
	int exitstatus;

	f_pid = fork();

	if(f_pid < 0){
		perror("fork failed");
		exit(1);
	}else if(f_pid == 0){
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execvp(argv[0], argv);           	
		fprintf(stderr, "execvp failed.\n");
		exit(EXIT_FAILURE);
	}else{
		waitpid(f_pid, &exitstatus, NULL);
		/* handle exitstatus */
	}
}
