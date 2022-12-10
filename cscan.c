#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int track[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int sc =0;
    printf("Seek Sequence\n");
    qsort(track, 8, sizeof(int), cmpfunc);
    int i =0;
    while(track[i] < head){
        i++;
    }
    for(int k=i;k<8;k++){
        if(k==i)
        sc += abs(track[k]-head);
        else
        sc += abs(track[k]-track[k-1]);  
        printf("%d\n",track[k]);
    }
    sc += 199-track[7];
    sc += 199;
    printf("0\n");
    for(int j=0;j<i;j++){
        if(j==0)
         sc += track[j];
         else
         sc += abs(track[j]-track[j-1]);
         printf("%d\n",track[j]); 

    }
    printf("Seek Count = %d\n",sc);
    return 0;
}