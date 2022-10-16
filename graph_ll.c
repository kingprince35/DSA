#include<stdio.h>



struct vertex{
    int data;
};
struct edge{
    int src;
    int dest;
    int cost;
};
int main(){
    struct vertex *vertices;//vertices
    struct edge *edges;//edges
    int i,s,d,c,j;
    int totalVertex;
    int totalEdges;
    printf("\nEnter total Vertex Count");
    scanf("%d",&totalVertex);//5

    printf("\nEnter total Edges");
    scanf("%d",&totalEdges);//6

    vertices = (struct vertex*) calloc(totalVertex,sizeof(struct vertex));
    edges = (struct edge*) calloc(totalEdges*2,sizeof(struct edge));

    for(i=0;i<totalVertex;i++){
        printf("\nEnter Vertex Value: ");
        scanf("%d",&vertices[i].data);
    }

    for(i=0;i<totalEdges*2;i++){ //2
        printf("enter source - destination - cost ");
        scanf("%d%d%d",&s,&d,&c);
        // 1 10 5
        //10 1 5
        edges[i].src=s;//2
        edges[i].dest=d;//50
        edges[i].cost=c;//5
        i++;
        edges[i].src=d;//2
        edges[i].dest=s;//50
        edges[i].cost=c;//5


    }

    for(i=0;i<totalVertex;i++){ // 0:2
            printf("\n %d is conneced with : ",vertices[i].data);//2
        for(j=0;j<totalEdges*2;j++){
            if(edges[j].src == vertices[i].data){
                    printf(" %d ",edges[j].dest);
            }
        }
    }
    return 0;
}
