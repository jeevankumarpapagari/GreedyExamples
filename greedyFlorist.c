#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int flowersCount, numberOfFriends;
    scanf("%d%d",&flowersCount,&numberOfFriends);

    int flowersCost[flowersCount],friendsHoldingFlowers[numberOfFriends],i;
    for(i=0;i<flowersCount;i++)
        scanf("%d",&flowersCost[i]);
    for(i=0;i<numberOfFriends;i++)
        friendsHoldingFlowers[i] = 0;
    
    qsort(flowersCost,flowersCount,sizeof(int),compare);

    int finalPrice = 0, j = 0;
    for(i=flowersCount-1;i>=0;i--)
    {
        finalPrice = finalPrice + (friendsHoldingFlowers[j]+1) * flowersCost[i];
        friendsHoldingFlowers[j]++;
        j = (j+1)%numberOfFriends;
    }

    printf("%d",finalPrice);
    return 0;
}