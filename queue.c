#include<stdio.h>
#define SIZE 5

int q[SIZE];
int f=-1,r=-1; //-1 empty

void insert(){
    int num;
    if(r == SIZE - 1 ){
        printf("\nQ Full");
    }else{
        printf("\nEnter number");
        scanf("%d",&num);
        r++;
        q[r] = num;
        if(f == -1){
            f++;
        }
    }
}

void deleteQ(){
    int num;
    if(f == -1){
        printf("\nQ is Empty");
    }else{
            num = q[f];
            printf("\n%d delete",num);
            if(f == r){
                    f=-1;
                    r=-1;
            }else{
                f++;
            }
            //printf("\n%d deleted",q[f++]);
    }
}

void display(){
    int i;
    printf("\nContent of the Q\n");
    for(i=f;i<=r;i++){
        printf("  %d",q[i]);
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



