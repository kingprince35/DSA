#include<stdio.h>

struct node{
	int data;
	struct node *left,*right;
	int height;
}*root= NULL;


struct node* rightRotate(struct node *root){//100
    struct node *leftchild,*leftchildright;

     leftchild =  root->left;
     leftchildright =  leftchild->right;

    leftchild->right = root;
    root->left = leftchildright;

    return leftchild;
}


struct node* leftRotate(struct node *root){//100
    struct node *rightchild,*rightchildleft;

     rightchild =  root->right;
     rightchildleft =  rightchild->left;

    rightchild->left = root;
    root->right = rightchildleft;

    return rightchild;
}


struct node* createNode(int data){
	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->height = 1;
	return tmp;
}

struct node *insertNode(struct node *root,int data){//100,150
	int bf;
	if(root == NULL){
		root =  createNode(data);//100
		return root;
	}else{
		if(data > root->data){
			root->right = insertNode(root->right,data);
		}else{
			root->left = insertNode(root->left,data);

		}
		root->height = calculateHeight(root);
		bf = getBalanceF(root);
        printf(" [%d %d] ",root->data,bf);

        if( !(bf>-2 && bf <2) ){
            printf(" *Rotation Required For %d *",root->data);

            //negt R
            if(bf < 0){
                if(data > root->right->data){
                    printf(" RR ");
                    return leftRotate(root);
                }else{
                    printf(" RL ");
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }else{
                //left
                if(data < root->left->data){
                    printf(" LL ");
                    return rightRotate(root);

                }else{
                    printf(" LR ");
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }

        }

	}

	return root;

 }

int calculateHeight(struct node *root){
	int lh=0,rh=0;
	if(root->left != NULL){
		lh = root->left->height; //1
	}
	if(root->right!=NULL){
		rh = root->right->height;//2
	}

	return  rh >= lh ? rh+1 : lh+1 ;
}

void inOrder(struct node *root){
	if(root == NULL)
		return;
	inOrder(root->left);
	printf(" [%d(%d)] ",root->data,root->height);
	inOrder(root->right);
}

int getBalanceF(struct node *root){
    int lh=0,rh=0;
    if(root==NULL){
        return 0;
    }
    if(root->left != NULL){
        lh = root->left->height;
    }
    if(root->right != NULL){
        rh = root->right->height;
    }
    return  lh - rh ;
}


int main(){
            printf("\n inserting 100");
 	root  = insertNode(root,100); //NULL,100
            printf("\n inserting 150");
    root  =        insertNode(root,150);//100,150
            printf("\n inserting 50");
        root  =    insertNode(root,50);
            //printf("\n inserting 300");
            //insertNode(root,300);


            //printf("\n inserting 110");
            //insertNode(root,110);
            printf("\n inserting 75");
         root  =   insertNode(root,75);

            printf("\n inserting 25");
       root  =     insertNode(root,25);

            printf("\n inserting 10");
       root  =     insertNode(root,10);

            printf("\n Tree \n");
             inOrder(root);
	return 0;
}



