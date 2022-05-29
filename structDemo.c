#include<stdio.h>

struct royal {
    char name[30];
    int m,s,e;
    float per;
};

int main()
{
 /*
    struct royal *r;
    int i;

    r = (struct royal*)malloc(sizeof(struct royal));

        printf("\nEnter name and marks of three subjects");
        scanf("%s%d%d%d",&r->name,&r->m,&r->s,&r->e);//
        printf("\n%s  %d  %d  %d",r->name,r->m,r->s,r->e);//
*/
    /*
    for(i=0;i<2;i++){
        printf("\nEnter name and marks of three subjects");
        scanf("%s%d%d%d",&r[i].name,&r[i].m,&r[i].s,&r[i].e);//
    }
    for(i=0;i<2;i++){
        printf("\n%s  %d  %d  %d",r[i].name,r[i].m,r[i].s,r[i].e);//
    }

    */

    struct royal *r;
    int i;

    r = (struct royal*)malloc(sizeof(struct royal)*3);


    for(i=0;i<2;i++){
        printf("\nEnter name and marks of three subjects");
        scanf("%s%d%d%d",&r[i].name,&r[i].m,&r[i].s,&r[i].e);//
    }
    for(i=0;i<2;i++){
        printf("\n%s  %d  %d  %d",r[i].name,r[i].m,r[i].s,r[i].e);//
    }



    return 0;

}
