#include<stdio.h>
#define SIZE 5
int a[SIZE];


int main(){
    int i,search,found=0,min=0,max=SIZE-1,mid;

    printf("\nEnter elements in ASC order");
    for(i=0;i<SIZE;i++){
        printf("Enter number ");
        scanf("%d",&a[i]);
    }

    printf("\nEnter number Search : ");
    scanf("%d",&search);


    while(min < max){

           mid = (min+max)/2;

           if(a[mid] == search){
                found = 1;
                printf("\n%d Found ",search);
                break;
           }else if(search > a[mid]){
                min = mid + 1;
           }else {
                max = mid - 1;
           }
    }

    if(!found)
            printf("\n%d NOT FOUND ",search);


    return 0;
}
