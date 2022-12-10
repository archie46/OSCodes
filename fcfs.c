#include<stdio.h>
#include<stdlib.h>

int main(){
    int track[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    int sc =0;
    printf("Seek Sequence\n");
    for(int i=0;i<8;i++){
        printf("%d\n",track[i]);
        if(i==0)
            sc+=abs(track[i]-head);
        else
            sc+=abs(track[i]-track[i-1]);
    }
    printf("Seek Count = %d\n",sc);
    return 0;
}