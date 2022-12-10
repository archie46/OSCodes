#include<stdio.h>
#include<stdbool.h>
int search(int arr[],int n,int item){
    for(int i =0;i<n;i++)
        if(arr[i] == item)
            return i;
    return -1;
}
int min(int arr[],int n){
  int ms = 0;
  for(int i =0;i<n;i++){
    if (arr[ms]>arr[i])
    ms = i;
  }
  return ms;
} 
int main(int argc, char const *argv[]){
    int pr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,3};
    int n = sizeof(pr)/sizeof(pr[0]);
     int nf = 4;
     int f[nf];
     int count[nf];
     for(int i =0;i<nf;i++){
     f[i] = -1;
     count[i] = -1;
     }
       int pf = 0;
       int ind ,l;  
     for(int i =0;i<n;i++){
      l = search(f,nf,pr[i]);
       if(l == -1){
        ind = min(count,nf);
        f[ind] = pr[i];
          pf++;
          count[ind]++;
       }
       else{
                count[l]++;  
       }

     }
    printf("Number Of Page Faults = %d\n",pf);
    return 0;
}
