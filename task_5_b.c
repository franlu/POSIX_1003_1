/*

task_5_b.c
Producer using FIFO communication mechanism
    
*/


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define FILE_FIFO "ComunicacionFIFO"

int main(int argc, char *argv[])
{
 int fd;

//Checking correct usage of the program.
if(argc != 2)  {
	printf("\nproducerFIFO: need arguments (message)");
	printf("\ntry: producerFIFO <message> where <message> is string.\n");
	exit(-1);
}

//open FIFO pipe to read.
if( (fd=open(FILE_FIFO,O_WRONLY)) <0) {
	perror("\nWrong open");
	exit(-1);
}

//write FIFO pipe with message. 
if( (write(fd,argv[1],strlen(argv[1])+1)) != strlen(argv[1])+1) {
	perror("\nError at FIFO pipe when write");
	exit(-1);
}
close(fd);

return 0;

}
