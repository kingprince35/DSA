#include<stdio.h>

struct node {
    int data;
    struct node *next;
}*head=NULL;

void insert();
void display();

int main(){
    int ch;

    while(1){
            printf("\n0 For exit\n1 For Insert\n2 For Display\nEnter choice");
            scanf("%d",&ch);

            switch(ch){
                case 0:
                        exit(0);
                case 1:
                        insert();break;
                case 2:
                        display();break;
            }

    }

}

void insert(){
    int num;
    struct node *tmp,*p;

    printf("\nEnter number");
    scanf("%d",&num);//10 20 30 40

        if(head == NULL){
            head = (struct node*) malloc(sizeof(struct node));
            head->data = num;
            head->next = NULL;
        }else{
            tmp = (struct node*) malloc(sizeof(struct node));
            tmp->data = num;
            tmp->next = NULL;

            p = head;
            while(p->next != NULL){
                p = p->next;
            }


            p->next = tmp;


        }
}
void display(){
    struct node *p;
    if(head == NULL){
        printf("\nNo element");
    }else{
        p = head;
        while(p != NULL){
            printf(" %d ",p->data);
            p=p->next;

        }

    }
}



