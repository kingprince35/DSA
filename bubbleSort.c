#include<stdio.h>

int n = 7;

int main(){

    int a[] = {11,2,33,4,5,17,9};
    int i,j,tmp,flag=0;
    printf("\nArray Before Sorted...\n");
    for(i=0;i<n;i++){
        printf("  %d",a[i]);
    }

    for(j=0;j<n-1 && flag == 0 ;j++){
        flag = 1;
        printf("\n PASS : %d\n",j+1);
        for(i=0;i<n-1;i++){
            if( a[i] > a[i+1]){
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                flag=0;
            }
        }
        for(i=0;i<n;i++){
            printf("  %d",a[i]);
        }
    }

    printf("\nArray After Sorted...\n");
    for(i=0;i<n;i++){
        printf("  %d",a[i]);
    }


    return 0;
}
