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

DIR *directorio;
struct dirent *file;
int fd;
struct stat atributos;

	if(argc<2) {
		printf("\nSintaxis de ejecucion: tarea4 [<pathname>]+ [<4digit_octal_number>]+ \n\n");
		exit(-1);
	}	

	directorio = opendir(argv[1]);

	file = readdir(directorio);
	while(file != NULL){
			printf("\nFile Name: %s",file->d_name);
			
			if( (fd=open(file->d_name,O_RDONLY,S_IRUSR))<0) {
				//printf("\nError %d en open",errno);
				perror("\nOpen Fail\n.");
				//exit(-1);
			}
		
			if(stat(file->d_name,&atributos) < 0) {
				//printf("\nError al intentar acceder a los atributos");
				//perror("\nstat Fail");
				//exit(-1);
			}
			close(fd);
			
			file = readdir(directorio);
	}
	
	if(closedir(directorio)<0) {
		printf("\nclosedir Fail \n\n");
		exit(-1);
	}
	

return 0;
}
