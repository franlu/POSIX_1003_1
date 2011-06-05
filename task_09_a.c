/*

task_09_a.c
Working with system calls Process Subsystem POSIX 2.10
    
*/

#include<sys/types.h> //Primitive system data types for abstraction of implementation-dependent data types.
                      //POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>    //POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{


int num_hijos = 5;
pid_t hijos[num_hijos];


for(int i=0;i<num_hijos;i++)
    if ( (hijos[i] = fork()) < 0){
        perror("\nError at fork call number %d ",i);
	exit(-1);
    } else {
        
    }
    
if(pid==0) {  //child process run the program
    sprintf(aux,"\nI am the son %d:\n",hijos[i]);
        if  (write(STDOUT_FILENO,aux,sizeof(aux)+1) != sizeof(aux)+1) {
            perror("\nError writing to STDOUT");
            exit(-1);
        }
    //call for end child process
}
		



exit(0);

}