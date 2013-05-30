/*************************************************************************
  > File Name: builtin.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2013年05月05日 星期日 13时24分27秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "builtin.h"

void do_cd(char *argv[]){
	assert(argv);
	char *dirtmp;

	if(argv[1] == NULL || strcmp(argv[1], "~") == 0){
		dirtmp = getenv("HOME");
		if(!dirtmp)
		{
			perror("HOME not set");
			exit(1);
		}

		chdir(dirtmp);	
	}else{
		dirtmp = argv[1];
		if(chdir(dirtmp) != 0){
			perror("wrong file or dir");
			exit(1);
		}
	}
}
