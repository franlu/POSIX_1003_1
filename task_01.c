/*
task_1.c
Working with system calls File System ''POSIX 2.10 compliant''
Try following the execution of the program: $>cat file y $> od -c file
*/

#include<sys/types.h>  	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>


int main(int argc, char *argv[]){
	
int fd,fd1;
int i=0; 
char buf[80];// size block
char buffer[2000];// Standar input
int hay_datos = 1;
	
	if (argc == 2){
		if( (fd=open(argv[1],O_RDONLY,S_IRUSR))<0) {
			printf("\nError %d en open",errno);
			perror("\nError en open del path.");
			exit(-1);
		}
	}
	else{
   
		printf("Introduce el contenido del fichero que se va a procesar: ");
		scanf("%s",buffer);
		if( (fd=open("entrada",O_CREAT | O_TRUNC | O_RDONLY,S_IRUSR|S_IWUSR))<0) {
			printf("\nError %d en open",errno);
			perror("\nError en open de entrada estandar.");
			exit(-1);
		}
		
		printf("entrada: %s",buffer);
    
		if(write(fd,buffer,2000) != 2000) {
			perror("\nError en write de la entrada estandar");
			exit(-1);
		}	 
		
	}//else
   
	if( (fd1=open("salida",O_CREAT|O_TRUNC|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
		printf("\nError %d en open",errno);
		perror("\nError en open del fichero de salida.");
		exit(-1);
	}

	// Calculate the number of blocks occupied by the file

	int tam;
	lseek(fd1,27,SEEK_SET);
		while(hay_datos){

			tam = read(fd,buffer,80);
			if (tam == 0)
				hay_datos=0;
			else{
				sprintf(aux,"\nBloque %d:\n",i);
				write(fd1,aux,12);
				write(fd1,buffer,tam);
				i++;
			}
		
        }//while

	close(fd);
	close(fd1);

return 0;
}
