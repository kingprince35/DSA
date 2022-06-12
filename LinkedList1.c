#include<stdio.h>

struct node {
    int data;
    struct node *next;
}*head=NULL;

void insert(int num);//insert last
void display();//1 - 2 - 3
void deleteNode();//delete last
void insertAtBeg();//insert beg
void insertAtAnyAfter();//insert at any after [! beg end ]
//1 2 3 4 5

void insertAtAnyBefore();
void deleteBeg();
void deleteAny(int num);

int main(){
    int ch;
    int num;
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);


    while(1){
            printf("\n0 For exit\n1 For Insert\n2 For Display\n3 For Delete");
            printf("\n4 For InsertAtBeg\n5 for InsertAtAnyAfter");
            printf("\n6 for InsertAtAnyBefore\n7 Delete Beg\n8 Delete Any");
            printf("\nEnter choice");
            scanf("%d",&ch);

            switch(ch){
                case 0:
                        exit(0);
                case 1:
                        printf("\nEnter number");
                        scanf("%d",&num);//10 20 30 40
                        insert(num);break;
                case 2:
                        display();break;
                case 3:
                        deleteNode();break;
                case 4:
                        printf("\nEnter number");
                        scanf("%d",&num);
                        insertAtBeg(num);break;
                case 5:
                        insertAtAnyAfter();break;
                case 6:
                        insertAtAnyBefore();break;
                case 7:
                        deleteBeg();break;
                case 8:
                        printf("\nEnter number that you want to delete");
                        scanf("%d",&num);
                        deleteAny(num);
                        break;
            }

    }

}

void insert(int num){

    struct node *tmp,*p;


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

void insertAtBeg(int num){


    struct node *tmp;

    if(head == NULL){
        printf("\nPlease Add node ");
    }else{


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


void insertAtAnyBefore(){
    struct node *p,*q,*tmp;
    int search,isFound=0,num;//0 -> not found

    if(head == NULL){
        printf("\nPlease Add Some Data");
    }else{
        printf("\nEnter Source Node:before");
        scanf("%d",&search);

        p = head;
        q    = head;
        while(p!=NULL){
            if(p->data == search){
                isFound = 1; //found
                break;
            }
            q = p;
            p = p->next; //p++
        }


        if(isFound == 1){

            printf("\nEnter new Data");
            scanf("%d",&num);
            if(p == head){
                insertAtBeg(num);
            }
            else
            {
                tmp =(struct node*) malloc(sizeof(struct node));
                tmp->data = num;
                q->next = tmp;
                tmp->next =p;
            }
        }else{
            printf("\nInvalid Source PTA");
        }
    }

}



void deleteBeg(){
    struct node *tmp;
    tmp = head;
    head = head->next;
    free(tmp);//malloc calloc free realloc

}

void deleteAny(int num){
    struct node *p,*q ;
    int isFound=0;//not found
    p = head;
    q=head;
    while(p!=NULL){
        if(p->data == num){
            isFound = 1;
            break;
        }
        q=p;
        p=p->next;
    }

    if(isFound){
        if(p==head){
            deleteBeg();
        }else if(p->next == NULL){
            deleteNode();
        }else{
            q->next = p->next;
            free(p);
        }
    }else{
        printf("\nInvalid Source PTA");
    }


}









