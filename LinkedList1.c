#include<stdio.h>

struct node {
    int data;
    struct node *next;
}*head=NULL;

void insert();
void display();
void deleteNode();
void insertAtBeg();
void insertAtAnyAfter();

int main(){
    int ch;

    while(1){
            printf("\n0 For exit\n1 For Insert\n2 For Display\n3 For Delete");
            printf("\n4 For InsertAtBeg\n5 for InsertAtAnyAfter\n");
            printf("\nEnter choice");
            scanf("%d",&ch);

            switch(ch){
                case 0:
                        exit(0);
                case 1:
                        insert();break;
                case 2:
                        display();break;
                case 3:
                        deleteNode();break;
                case 4:
                        insertAtBeg();break;
                case 5:
                        insertAtAnyAfter();break;
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

void deleteNode(){

    struct node *p,*q;
    if(head == NULL)
        printf("\nList is empty");
    else{
        p = head;
        while(p->next != NULL)
            p=p->next;

        q = head;
        while(q->next != p){
            q=q->next;
        }
        printf("\n%d Removed ",p->data);
        free(p);
        q->next = NULL;
    }
}

void insertAtBeg(){

    int num;
    struct node *tmp;

    if(head == NULL){
        printf("\nPlease Add node ");
    }else{
        printf("\nEnter number");
        scanf("%d",&num);

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = head;
        head = tmp;

    }
}

void insertAtAnyAfter(){
    //head
    int search,flag = 0,num;//0 not
    struct node *p,*q,*tmp;

    printf("\nEnter number after you want to add new data");
    scanf("%d",&search);

    p = head;

    while(p != NULL){
        if(p->data == search){
            flag = 1;
            break;
        }
        p=p->next;
    }

    if(flag == 1){
        printf("\nEnter new number");
        scanf("%d",&num);

        q = p->next;

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data= num;
        tmp->next = q;
        p->next=tmp;


    }else{
        printf("\nNumber not found in list PTA");
    }

}


















