/*

task_8.c
Working with system calls Process Subsystem POSIX 2.10
A pipe example program and input-output standard redirection: "ls | sort"
using the call dup2
    
*/

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char *argv[])
{
 int fd[2];
 pid_t PID;

 pipe(fd); // System call to make pipe

 if ( (PID= fork())<0)  {
   perror("\Error en fork");
   exit(-1);
 }
if (PID == 0) {  // ls // child process
  ///Close of read descriptor in the child process
  close(fd[0]);

  //Duplicar el descriptor de escritura en cauce en el descriptor
  //correspondiente a la salida estandar (stdout), cerrado previamente en
  //la misma operacin. 
  dup2(fd[1],STDOUT_FILENO);

  execlp("ls","ls",NULL);
} 
else  { // sort. // PID != 0 father process 
  ///Close of write descriptor in the father process
  close(fd[1]);

  //Duplicar el descriptor de lectura de cauce en el descriptor
  //correspondiente a la entrada estándar (stdin), cerrado previamente en
  //la misma operación. 
  dup2(fd[0],STDIN_FILENO);
  
  execlp("sort","sort",NULL);
}

return(0);

}