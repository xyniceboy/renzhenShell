#include "common.h"

char prompt[PROMPT_LEN];

/*lurk memory leak bug*/
void set_prompt(char *prompt){
  snprintf(prompt, PROMPT_LEN, "%s@Think-pad:%s$", getenv("USER"), getcwd(NULL, 0));
}

void cmd_to_argv(char *strp, char *argv[])
{
	assert(strp && argv);

	int i =	1;
	
	argv[0] = strp;
	while(*strp != '\0'){	//go through the cmd
		if(*strp == ' ' || *strp == '\t' || *strp == '\n'){
			*strp++ = '\0';
			while(*strp==' ' || *strp == '\t') strp++;
			argv[i++] = strp;
		}
		strp++;
	}

	argv[i] = NULL;		//obey the argv format, terminated by NULL
}

