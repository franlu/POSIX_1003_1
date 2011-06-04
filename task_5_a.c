/*
task_5_a.c
Consumer using FIFO communication mechanism
    run: $>consumerFIFO & (background)
    after run producerFIFO
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define FILE_FIFO "ComunicacionFIFO"

int main(void)
{
int fd;
char buffer[80];//Client message.
int leidos;

//make pipe FIFO
umask(0);
printf ("Return value for mknod: %d\n", mknod(FILE_FIFO,  S_IFIFO|0666, 0));

//mkfifo(FILE_FIFO,0666); is valid

//Open pipe to read
if( (fd=open(FILE_FIFO,O_RDWR)) <0) {
    perror("open");
    exit(-1);
}

//Accept data to consume up to send the string fin

while (1) {
	leidos =read(fd, buffer, 80);
	if(strcmp(buffer,"fin")==0){
	  close(fd);
	  return 0;
	}
	printf("\nMessage OK: %s\n",buffer);

}

return 0;

}
