#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * m1(){
    system("cvlc CantinaBand60.wav");
    sleep(5);
   return NULL;
}

void * m2(){
    system("cvlc StarWars60.wav");
    sleep(1);
   return NULL;
}
int main(int argc, char const *argv[]){
    pthread_t t1;
   // pthread_t t2;
    pthread_create(&t1,NULL,&m1,NULL);
   // pthread_create(&t2,NULL,&m2,NULL);
    pthread_join(t1,NULL);
   // pthread_join(t2,NULL);
    
    return 0;
}

