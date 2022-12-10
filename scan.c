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
    sc += abs(head-track[i-1]);
    for(int j=i-1;j>=0;j--){
        if(j==0)
          sc += track[j];
        else
          sc += abs(track[j]-track[j-1]);  
        printf("%d\n",track[j]);
    }
    printf("0\n%d\n",track[i]);
    sc += track[i];
    for(int k=i+1;k<8;k++){
        sc += abs(track[k]-track[k-1]);  
        printf("%d\n",track[k]);
    }
    printf("Seek Count = %d\n",sc);
    return 0;
}