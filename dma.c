#include<stdio.h>


int main(){


    int *a,i;

    a = (int*)malloc(5*sizeof(int));//5*2 =  10

    for(i=0;i<5;i++){
        printf("\nEnter number");
        scanf("%d",&a[i]);//a+i
    }

    for(i=0;i<5;i++){
        printf("\n%d",*(a+i));//baseaddress+i
        //printf("\n%d",a[i]);//
    }

    free(a);


    return 0;

}
