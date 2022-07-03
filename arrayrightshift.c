#include<stdio.h>
#define SIZE 5

int a[]  = { 1,2,3,4,5};
//1 2 3 4 5
//5 1 2 3 4
void rightShift(int shiftCount){//3 2 1
    int tmp;
    int i,j;


    tmp = a[SIZE-1];
    for(i=SIZE-1;i>0;i--){
        a[i] = a[i-1];
    }
    a[0] = tmp;
    shiftCount--;
    if(shiftCount != 0 )
        rightShift(shiftCount);

}


//1 2 3 4 5
//rs() rs()
//4 5 1 2 3

void print(){
    int i;
    printf("\n");
    for(i=0;i<SIZE;i++){
        printf(" %d",a[i]);
    }
}
int main(){
    print();
    rightShift(3);
    print();
    return 0;
}
