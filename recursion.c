#include<stdio.h>

void fibo(int a,int b,int c);

int main(){

    fibo(1,1,5);//1 1 2 3 5
    return 0;
}

void fibo(int a,int b,int c){//1 1 5
    printf("%d ",a);//1 1
    c--;
    if(c!=0)
        fibo(b,a+b,c);
}
