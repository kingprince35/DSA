#include<stdio.h>
#define N 5

int main(){

    int a[] = {21,1,5,10,7};
    int i,j,x,sort;

    printf("\nArray Before Sorting...\n");
    for(x=0;x<N;x++){
        printf("  %d",a[x]);
    }
    //sorting

    for(i=1;i<N;i++){
        sort = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j] > sort ){
                a[j+1] = a[j];
            }else{
                break;
            }
        }
        a[j+1] = sort;
    }

    printf("\nArray AFter Sorting...\n");
    for(x=0;x<N;x++){
        printf("  %d",a[x]);
    }
    return 0;
}
