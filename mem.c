#include<stdio.h>
void print(int al[],int n){
    printf("\nProcess Allocated Block\n");
    for(int i = 0;i<n;i++){
         if(al[i] > 0)
         printf("%5d    Yes      %d\n",i+1,al[i]);
         else
         printf("%5d    No       - \n",i+1);
    }	
}
void firstFit(int np,int nb,int b[],int psize[]){
    int al[np];
    for(int i =0;i<np;i++)
    al[i] = -1;
    int bsize[nb];
    for(int i =0;i<nb;i++)
    bsize[i] = b[i];
    for(int i =0;i<np;i++){
        for(int j =0;j<nb;j++){
            if(psize[i] <= bsize[j]){
                al[i] = j+1;
                bsize[j] -= psize[i]; 
                break;
            }
        }
    }

  print(al,np);
}
void nextFit(int np,int nb,int b[],int psize[]){
    int al[np];
    for(int i =0;i<np;i++)
    al[i] = -1;
    int bsize[nb];
    for(int i =0;i<nb;i++)
    bsize[i] = b[i];
    int p = 0;
    for(int i =0;i<np;i++){
        for(int j =p;j<nb;j++){
            if(psize[i] <= bsize[j]){
                al[i] = j+1;
                bsize[j] -= psize[i]; 
                p++;
                break;
            }            
        }
    }

  print(al,np);
}

void bestFit(int np,int nb,int b[],int psize[]){
    int al[np];
    for(int i =0;i<np;i++)
    al[i] = -1;
    int bsize[nb];
    for(int i =0;i<nb;i++)
    bsize[i] = b[i];
    for(int i =0;i<np;i++){
         int best = -1;
         int val,cval ;
        for(int j =0;j<nb;j++){
            if(best == -1){
            if(bsize[j] > psize[i]){
                val = bsize[j] - psize[i];
                best = j;
            }
            }
            else{
                cval = bsize[j]-psize[i];
                if(cval >= 0 && cval <val){
                    best = j;
                    val = bsize[j] - psize[i];
                }
            }
         }
         bsize[best] -= psize[i];
    al[i] = best +1;
    }
  print(al,np);
}

void worstFit(int np,int nb,int b[],int psize[]){
   int al[np];
    for(int i =0;i<np;i++)
    al[i] = -1;
    int bsize[nb];
    for(int i =0;i<nb;i++)
    bsize[i] = b[i];
    for(int i =0;i<np;i++){
         int best = -1;
         int val,cval ;
        for(int j =0;j<nb;j++){
            if(best == -1){
            if(bsize[j] > psize[i]){
                val = bsize[j] - psize[i];
                best = j;
            }
            }
            else{
                cval = bsize[j]-psize[i];
                if(cval >= 0 && cval > val){
                    best = j;
                    val = bsize[j] - psize[i];
                }
            }
         }
         bsize[best] -= psize[i];
    al[i] = best +1;
    }
  print(al,np);
}

int main(){
    int nb = 5;
    int bSize[] = {100,500,200,300,600};
    int np = 4;
    int pSize[]= {212,417,112,426};
     printf("\nUsing First Fit");
     firstFit(np,nb,bSize,pSize);
     printf("\nUsing Next Fit");
     nextFit(np,nb,bSize,pSize); 
     printf("\nUsing Best Fit");
     bestFit(np,nb,bSize,pSize); 
     printf("\nUsing Worst Fit");
     worstFit(np,nb,bSize,pSize);   
    return 0;
}

