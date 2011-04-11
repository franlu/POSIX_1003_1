/*
task_4.c
Standard management functions Directory ''POSIX 2.10 compliant''
*/

#include<sys/types.h>  	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

#include<dirent.h>


int main(int argc, char *argv[]){
	
if(argc<2) {
	printf("\nSintaxis de ejecucion: tarea4 [<pathname>]+ [<4digit_octal_number>]+ \n\n");
	exit(-1);
}	

return 0;
}
