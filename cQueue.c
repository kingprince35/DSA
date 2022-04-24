#include<stdio.h>
#define SIZE 5

int q[SIZE];
int f=-1,r=-1; //-1 empty

void insert(){
    int num;
    if(r == SIZE - 1 && f == 0 ){
        printf("\nQ Full");
    }else if( r ==  f-1 ){
        printf("\nQ Full");
    }else{
        printf("\nEnter number");
        scanf("%d",&num);
        if(f == -1){
            f++;
        }
        if(r == SIZE - 1){
            r = 0;
        }else{
            r++;
        }
        q[r] = num;

    }
}

void deleteQ(){
    int num;
    if(f == -1){
        printf("\nQ is Empty");
    }else{
            num = q[f];
            printf("\n%d delete",num);

            if(f == r){ // last element
                    f=-1;
                    r=-1;
            }else if(f == SIZE - 1){
              f = 0;
            }else{
                f++;
            }
            //printf("\n%d deleted",q[f++]);
    }
}

void display(){
    int i;
    if(f == -1){
        printf("\nQ is Empty");
    }else{
        printf("\nContent of the Q\n");

        if(r >= f){
            for(i=f;i<=r;i++){
                printf("  %d",q[i]);
            }
        }else if( r < f ){
            for(i=f;i<SIZE;i++){
                printf("  %d",q[i]);
            }
            for(i=0;i<=r;i++){
                printf("  %d",q[i]);
            }
        }
    }

}

int main(){
        int choice;
        while(1){

        printf("\n0 for Exit\n1 For Insert\n2 For Delete\n3 For Display\nEnter your choice!!!");
        scanf("%d",&choice);

        switch(choice){
        case 0:
                exit(0);
        case 1:
                insert();break;
        case 2:
                deleteQ();break;
        case 3:
                display();break;

        }//switch
        }//while

    return 0;

}



