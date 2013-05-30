mysh:mysh.o builtin.o common.o
  gcc -o mysh mysh.o builtin.o common.o  -lreadline -ltermcap
mysh.o:mysh.c
	gcc -c  mysh.c
builtin.o:builtin.c 
	gcc -c  builtin.c 
common.o:common.c 
	gcc -c  common.c 

clean:
	rm -f  common.o builtin.o mysh.o
