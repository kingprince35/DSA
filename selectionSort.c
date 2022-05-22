#include<stdio.h>

int n = 7;

int main(){

//    int a[] = {1,2,33,14,15,16,9};
      int a[] = {1,2,33,144,156,166,900};

    int i,j,tmp,flag=0,min,x;
    printf("\nArray Before Sorted...\n");
    for(i=0;i<n;i++){
        printf("  %d",a[i]);
    }

    for(i=0;i<n-1;i++){
            min = i;
        printf("\nPASS %d\n",i+1);
        for(j=i+1;j<n;j++){
            if(a[min] > a[j]){
                min = j ;
            }
        }
        if(i != min){
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
        for(x=0;x<n;x++){

            printf("  %d",a[x]);
        }
    }

    printf("\nArray After Sorted...\n");
    for(i=0;i<n;i++){
        printf("  %d",a[i]);
    }


    return 0;
}
