#include<stdio.h>

int main(){
    int avr[3]= {10,5,7};
    int all[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int maxn[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {4,2,2},
        {5,3,3}
    };
    int remn[5][3];
    int ta[3]= {0,0,0};
    for(int i = 0;i<3;i++){
        for(int j = 0;j<5;j++){
        	remn[j][i] = maxn[j][i] - all[j][i];
        	ta[i] += all[j][i];
		}
                  	
	}
	int av[3];
    for(int i  =0;i<3;i++){
    	av[i] = avr[i] - ta[i];
    //	printf("%d ",av[i]);
	}
	int counter=0;
	int boo[5] = {0,0,0,0,0};
	printf("Safe Sequence is\n");
    while(counter != 5){
    	for(int i =0;i<5;i++){
    	int count = 0;
    	if( boo[i] == 0){
    	for(int j =0;j<3;j++){
    		if(av[j]>=remn[i][j]){
    			count++;
			}
		}

		}
    	if(count == 3){
			printf("Process %d \n",i+1);
			counter++;
			boo[i] = 1;
			for(int k =0;k<3;k++){
				av[k]+= all[i][k];
			}
		}
	}
	}
    
    return 0;
}
