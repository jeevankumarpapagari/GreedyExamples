#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int totalNumberOfToys, remainingAmount;
    scanf("%d%d",&totalNumberOfToys,&remainingAmount);
    
    int toyPriceList[totalNumberOfToys],i;
    for(i=0;i<totalNumberOfToys;i++)
        scanf("%d",&toyPriceList[i]);
    
    qsort(toyPriceList,totalNumberOfToys,sizeof(int),compare);

    i = 0;
    int result = 0, sum = 0;
    while(sum + toyPriceList[i] <= remainingAmount)
    {
        result++;
        sum = sum + toyPriceList[i++];
    }
    printf("%d",result);
    return 0;
}