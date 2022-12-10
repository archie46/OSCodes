#include<stdio.h>
#include<stdbool.h>
int search(int arr[],int n,int item){
    for(int i =0;i<n;i++)
        if(arr[i] == item)
            return i;
    return -1;
} 
int main(int argc, char const *argv[]){
    int pr[] = {1,3,0,3,5,6,3};
    int n = sizeof(pr)/sizeof(pr[0]);
     int nf = 3;
     int f[nf];
     for(int i =0;i<nf;i++)
     f[i] = -1;
       int pf = 0;
       int ind = 0;  
     for(int i =0;i<n;i++){
       if(search(f,nf,pr[i]) == -1){
        f[ind] = pr[i];
          pf++;
          ind = (ind+1)%nf;
       }
     }
    printf("Number Of Page Faults = %d\n",pf);
    return 0;
}
