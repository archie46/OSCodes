#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int fd[2];
	int b[10];
	pid_t p;
	pipe(fd);
	p = fork();
	if(p>0){
                int a[10];
                printf("Passing Array of Numbers To Child Process\n");
                for(int i =0;i<10;i++){
                    a[i]  = i+1;
		    printf("%d ",a[i]);        
		} 
		printf("\n");         
		write(fd[1],a,sizeof(int)*10);
	}
	else{
		printf("Array Containing Square Of Numbers Recieved\n");
		read(fd[0],b,sizeof(int)*10);
		for(int i =0;i<10;i++){
		        b[i] = b[i] * b[i];
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}

