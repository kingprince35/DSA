#include<stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;

}*root=NULL;


struct node* createNode(int num){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;

}

struct node* addNode(int num,struct node *root){//100,(50) | 100,NULL
        if(root==NULL){
           root = createNode(num);
        }else{
            if(root->data > num ){
                //left
                root->left =  addNode(num,root->left);//100,NULL
            }else{
                //right
                root->right =  addNode(num,root->right);//100,NULL
            }
        }

        return root;
}


int main(){
    int i=1;

    root = addNode(50,root);//NULL
           addNode(100,root);//50
            addNode(35,root);
            addNode(25,root);
            addNode(40,root);
            addNode(150,root);
            addNode(250,root);

            //1 for add
            //2 for print
            //print(root);
    printf("\n%d ",root->data);//50
    printf("\n%d ",root->left->data);//35
    printf("\n%d ",root->left->left->data);//25
    printf("\n%d ",root->left->right->data);//40
    printf("\n%d ",root->right->data);//100
    printf("\n%d ",root->right->right->data);//150
    printf("\n%d ",root->right->right->right->data);//250



    return 0;
}
