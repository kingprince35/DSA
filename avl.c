#include<stdio.h>
struct node{
    int data;
    struct node *left,*right;
    int height; //1
}*root=NULL;

struct node* createNode(int data){
    struct node *tmp = NULL;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}
int calculateHeight(struct node *root){
    int lh=0;
    int rh=0;

    if(root->left != NULL){
        lh = root->left->height;//1
    }
    if(root->right != NULL){
        rh = root->right->height;//1
    }

    if(lh > rh){
        return lh + 1 ;
    }else{
        return rh + 1;
    }

}
struct node*  insertNode(struct node *root,int data){//(100,150) => (NULL,70)
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(data < root->data ){
        root->left = insertNode(root->left,data);
    }else{
        root->right = insertNode(root->right,data);
    }

    root->height = calculateHeight(root);
    return root;
}

void inOrder(struct node *root){

    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d(%d)  ",root->data,root->height);
    inOrder(root->right);

}
int main(){

    root = insertNode(root,100);
            insertNode(root,70);
            insertNode(root,150);
            insertNode(root,300);

            inOrder(root);
    return 0;

}
