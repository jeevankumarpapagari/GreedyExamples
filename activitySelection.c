#include<stdio.h>
#include<stdlib.h>
struct job
{
    int start;
    int stop;
};

int compare(const void *a,const void *b)
{
    return (((struct job*)a)->stop) - (((struct job*)b)->stop);
}

int main()
{
    int n;
    scanf("%d",&n);
    struct job list[n];
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d%d",&list[i].start,&list[i].stop);
    
    qsort(list,n,sizeof(struct job),compare);

    for(i=0;i<n;i++)
        printf("\nJob No: %d ==> {%d,%d} ",i+1,list[i].start,list[i].stop);

    i = 0;
    printf("\n\nJob: %d ",i+1);
    for(j=1;j<n;j++)
    {
        if(list[j].start >= list[i].stop)
        {
            printf("\nJob: %d ",j+1);
            i = j;
        }
    }
    return 0;
}