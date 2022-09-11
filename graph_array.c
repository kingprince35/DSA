#include<stdio.h>
#define SIZE 4


//graph

int graph[SIZE][SIZE];
int visited[SIZE];
int cost = 0 ;
int visitCount = 0 ;
void addEdge(int src,int dest,int cost){//0,3 => 1 3,0 => 1
     graph[src][dest] = cost;
     graph[dest][src] = cost;
}

int main(){

    int i,j,ans;
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
    i=0;
    while(visitCount != SIZE){//0
        //0  2   1  3
         for(j=0;j<SIZE;j++){//0   1 2 3
            if(graph[i][j] != -1){
                if( visited[j] == 0){
                    printf(" %d -> ",j);//2 1 3
                    cost = cost + graph[i][j];//0+5+4+4
                    visited[j] = 1;
                    visitCount++;//4
                    i=j;
                    break;
                }
            }
        }
    }


    return 0;

}
