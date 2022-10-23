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
    struct edge tmp;
    int i,s,d,c,j;
    int totalVertex;
    int totalEdges;
    printf("\nEnter total Vertex Count");
    scanf("%d",&totalVertex);//5

    printf("\nEnter total Edges");
    scanf("%d",&totalEdges);//6 [ 0-1 ,1-0 ] 6*2  = 12

    vertices = (struct vertex*) calloc(totalVertex,sizeof(struct vertex));
    edges = (struct edge*) calloc(totalEdges*2,sizeof(struct edge));

    for(i=0;i<totalVertex;i++){
        printf("\nEnter Vertex Value: ");
        scanf("%d",&vertices[i].data);//1 2 3 4 5
    }

    for(i=0;i<totalEdges*2;i++){ //2
        printf("enter source - destination - cost ");
        scanf("%d%d%d",&s,&d,&c);//1 5 5   ==> 5 1 5
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
            printf("\n %d is conneced with : ",vertices[i].data);//1
        for(j=0;j<totalEdges*2;j++){
            if(edges[j].src == vertices[i].data){
                    printf(" %d ",edges[j].dest);
            }
        }
    }


    //sort all edges

    for(i=0;i<totalEdges*2;i++){
        for(j=0;j<totalEdges*2-1;j++){
            if(edges[j].cost > edges[j+1].cost){

                tmp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = tmp;
            }
        }
    }

    printf("\nSorted Edges\n");


    for(i=0;i<totalEdges*2;i++){

       printf("\n%d  %d   %d",edges[i].src,edges[i].dest,edges[i].cost);
    }

    //sorted


    return 0;
}
