
#include<stdio.h>
#define SIZE 7


//static -
//register

//graph

int graph[SIZE][SIZE];//7*7 => 49
int visited[SIZE];
int cost;// extern [0]
int visitCount = 0 ;
int f=-1,r = -1;
int queue[SIZE];
int found = -1;


void insert(int num){
    if(f == - 1)
        f=0;
    r++;
    queue[r] = num;
}
int dequeue(){
  //  int num = stack[top];
  //  top--;
  //  return num;
 // printf(" *%d*%d* ",f,queue[f]);
  return queue[f++];
}

void addEdge(int src,int dest,int cost){//0,3 => 1 3,0 => 1
    int x=10;
    graph[src][dest] = cost;
     graph[dest][src] = cost;
}

int main(){

    int i,j,ans;// auto [g.v]
    /*
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(graph[i][j] == 0){
                printf("\n%d is connected with %d\n",i,j);//0,2 ? -1
                scanf("%d",&ans);//1 - connected and -1 not connected
                if(ans == -1 ){
                    graph[i][j]= -1;//0,2 => -1
                    graph[j][i]= -1;//2,0 => -1
                }else{
                    addEdge(i,j,ans);//0,1
                }
            }
        }
        printf("\n\n");
    }
    */
    addEdge(0,1,1);
    addEdge(0,5,1);
    addEdge(1,2,1);
    addEdge(1,4,1);
    addEdge(2,3,1);
    addEdge(3,6,1);
    addEdge(4,6,1);
    addEdge(5,6,1);


    for(i=0;i<SIZE;i++){
        printf("\n%d is connected with : ",i);
        for(j=0;j<SIZE;j++){
                if(graph[i][j] != -1){
                    printf(" %d(%d) ",j,graph[i][j]);
                }
        }
    }

    printf("\nGraph Travel := \n");

    printf(" %d -> ",0);
    visited[0] = 1 ;
    visitCount++;
    i=0;//currentNode
    while(visitCount != SIZE){//5
        //0  2   1  3

         for(j=0;j<SIZE;j++){//0 1 2 3 4 5 6
            if(graph[i][j] == 1){
               // printf("\n%d %d %d\n",i,j,graph[i][j]);
                if( visited[j] == 0){
                    printf(" %d -> ",j);//1

                    visited[j] = 1;
                    visitCount++;//4
                    insert(j); // queue-> insert


                }
            }
        }

            i = dequeue();
           // printf("\n i change => %d :",i);

    }

//     printf("\n total cost => %d  ",cost);

    return 0;

}
