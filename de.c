#include<stdio.h>

int main(){
    printf("Enter Number Of Resources:");
    int n;
    scanf("%d",&n);
    int avr[n];
    for(int i= 0;i<n;i++){
        printf("Enter The Available Number Of Instances Of Resource %d:",i+1);
        scanf("%d",&avr[i]);
    }
    printf("Enter Number Of Processes:");
    int p;
    scanf("%d",&p);
    int all[p][n];
    for(int i =0;i<p;i++){
        printf("Enter The Instances Of Each Resource Allocated To Process %d\n",i+1);
        for(int j=0;j<n;j++){
               printf("Resource %d:",j+1);
               scanf("%d",&all[i][j]);
        }
    }

    int maxn[p][n];
    for(int i =0;i<p;i++){
        printf("Enter The Maximum Number of Instances Of Each Resource Needed By Process %d\n",i+1);
        for(int j=0;j<n;j++){
               printf("Resource %d:",j+1);
               scanf("%d",&maxn[i][j]);
        }
    }    
    int remn[p][n];
    int ta[n];
    for(int i =0;i<n;i++)
    ta[i]= 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<p;j++){
        	remn[j][i] = maxn[j][i] - all[j][i];
        	ta[i] += all[j][i];
		}
                  	
	}
	
	int av[n];
    for(int i  =0;i<n;i++){
    	av[i] = avr[i] - ta[i];
	}
	int counter=0;
	int boo[p];
    for(int i =0;i<p;i++)
    boo[i]= 0;
	printf("Safe Sequence is\n");
	int flag;
    do{
    	for(int i =0;i<p;i++){
    	int count = 0;
    	if( boo[i] == 0 ){
    	for(int j =0;j<n;j++){
    		if(av[j]>=remn[i][j]){
    			count++;
			}
		}
 
		}
    	if(count == n){
    		flag = 1;
		//	printf("Process %d \n",i+1);
			counter++;
			boo[i] = 1;
			for(int k =0;k<n;k++){
				av[k]+= all[i][k];
			}
		}
	}
	}while(counter != p && flag == 1);
    if (counter != p)
    printf("System Is In Unsafe State\n");
    else
    printf("System Is In Safe State\n"); 
         
    return 0;
}
