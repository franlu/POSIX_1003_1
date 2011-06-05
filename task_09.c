/*

task_09.c
Working with system calls Process Subsystem POSIX 2.10
Test the program, then delete the comments (1) and try it again
    
*/

#include<sys/types.h> //Primitive system data types for abstraction of implementation-dependent data types.
                      //POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>    //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int global=6;
char buf[]="Testing the standard output\n";

int main(int argc, char *argv[])
{
int var;
pid_t pid;

var=88;
if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
	perror("\nError at write call");
	exit(-1);
}
//(1)   if(setvbuf(stdout,NULL,_IONBF,0)) {
//(1)   perror("\nError at setvbuf call");
//(1)   }

if(setvbuf(stdout,NULL,_IONBF,0)) {
	perror("\nError at setvbuf call");
}

printf("\nBefore fork() call");

if( (pid=fork())<0) {
	perror("\nError at fork call");
	exit(-1);
}
else if(pid==0) {  //child process run the program
		global++;
		var++;
		  execlp("/bin/ls","ls","-a", NULL);
	} else  //father process run the program
		sleep(1);
		
printf("\npid= %d, global= %d, var= %d\n", getpid(),global,var);
exit(0);

}