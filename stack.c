#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top=-1;

    void push(){
        int num;
        if(top == SIZE - 1){
            printf("\nStack Overflow");
        }else{
            printf("\nEnter number");
            scanf("%d",&num);
            top++;
            stack[top] = num ;
        }
    }
    void pop(){
        int num;
        if(top == -1){
            printf("\nStack Underflow");
        }else{
            num = stack[top];
            top--;
            printf("\n%d POP",num);
        }
    }
    void display(){
            int i;
            if(top == -1){
                printf("\nStack Underflow");
            }else{
                for(i=top;i>=0;i--){
                    printf("\n%d",stack[i]);
                }
            }
    }


int main(){

    int ch;
    while(1){ //0 false
        printf("\n0 for exit\n1 For Push\n2 For Pop\n3 for Display");
        printf("\nPlease Enter choice");
        scanf("%d",&ch);


        switch(ch){
        case 0:
            exit(0);
        case 1:
                push();
                break;
        case 2:
                pop();
                break;
        case 3:
                display();
                break;
        default:
            printf("\nInvalid Choice PTA");
        }//switch
    }//while 1

    return 0;
}
