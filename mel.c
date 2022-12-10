#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int size;
    struct node* next;
}node;

node * blocks;
node * processes;
void print(int al[],int n){
    printf("\nProcess Allocated Block\n");
    for(int i = 0;i<n;i++){
         if(al[i] > 0)
         printf("%5d    Yes      %d\n",i+1,al[i]);
         else
         printf("%5d    No       - \n",i+1);
    }	
}

void firstFit(int np,int nb){
    int al[np];
    for(int i =0;i<np;i++)
    al[i] = -1;
    int i = 0;
    while(processes != NULL){
        node * ptr = blocks;
        int j = 0;
        while(ptr != NULL){
            if(processes->size <= ptr->size){
                al[i] = j+1;
                ptr->size -= processes->size; 
                break;
            }
            j++;
            ptr = ptr->next;
        }
        i++;
        processes = processes ->next; 
    }
    print(al,np);
}

int main(int argc, char const *argv[]){
     node * b1 = malloc(sizeof(node));
     node * b2 = malloc(sizeof(node));
     node * b3 = malloc(sizeof(node));
     node * b4 = malloc(sizeof(node));
     node * b5 = malloc(sizeof(node));

     node * p1 = malloc(sizeof(node));
     node * p2 = malloc(sizeof(node));
     node * p3 = malloc(sizeof(node));
     node * p4 = malloc(sizeof(node));

     b1->size = 500;
     b1->next  = b2;

     b2->size = 900;
     b2->next  = b3;

     b3->size = 600;
     b3 ->next = b4;

     b4->size = 700;
     b4->next = b5;

     b5->size = 1000;
     b5->next = NULL;

     p1->size = 625;
     p1->next = p2;

     p2->size = 890;
     p2->next = p3;

     p3->size = 525;
     p3->next = p4;

     p4->size = 920;
     p4->next = NULL;

     
     blocks = b1;
     processes = p1;
     firstFit(4,5);
    return 0;
}
