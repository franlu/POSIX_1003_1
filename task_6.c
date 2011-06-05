/*

task_6.c
Working with system calls Process Subsystem POSIX 2.10
A pipe example program
    
*/

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


int main(int argc, char *argv[])
{
 int fd[2], numBytes;
 pid_t PID;
 char mensaje[]= "\nthe first message sent by the pipe!!\n";
 char buffer[80];

 pipe(fd); // System call to make pipe

 if ( (PID= fork())<0)  {
   perror("fork");
   exit(1);
 }
 
 if (PID == 0)  {	
   //Close of read descriptor in the child process
   close(fd[0]);

   // Send the message through the pipe using the write descriptor.
   write(fd[1],mensaje,strlen(mensaje)+1);
   exit(0);
 } 
 else {	// PID != 0 father process 
    //Close of write descriptor in the father process
    close(fd[1]);

    //Read data from pipe.
    numBytes= read(fd[0],buffer,sizeof(buffer));
    printf("\nEl número de bytes recibidos es: %d",numBytes);
    printf("\nLa cadena enviada a través del cauce es: %s", buffer);
}

 return(0);

}