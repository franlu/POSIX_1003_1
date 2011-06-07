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



int main(int argc, char *argv[]){

int num_hijos = 2;
int i,estado;
pid_t pid,pida;
char aux[20];


for(i=0;i<num_hijos;i++)
    if ( (pid = fork()) < 0){
        perror("\nError at fork call");
	exit(-1);
    }
    
if(pid==0) {  //child process run the program
    
    sleep(1);
    printf("\nI am the son %d \n",getpid());
    
}
else {
   
   for(i=0;i<num_hijos;i++){
	pida =  wait(&estado);
	printf("\nMi hijo %d ha finalizado con estado %d",pida,estado);
	printf("\nTengo %d hijos vivos.",num_hijos-i);
    }
  }


exit(0);

}