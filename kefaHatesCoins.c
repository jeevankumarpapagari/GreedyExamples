#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int main() 
{
    int totalCoins, totalGifts;
    scanf("%d %d",&totalCoins,&totalGifts);
    
    int arrCoins[totalCoins], i, j;
    for(i=0;i<totalCoins;i++)
        scanf("%d",&arrCoins[i]);
    
    qsort(arrCoins,totalCoins,sizeof(int),compare);
    
    int giftPrice;
    for(i=0,j=0;i<totalGifts;i++)
    {
        scanf("%d",&giftPrice);
        int startValue = 0, flag = 0, counter = 0;
        while(startValue < giftPrice)
        {
            if(j==totalCoins)
            {
                flag = 1;
                break;
            }
            startValue = startValue + arrCoins[j];
            j++;
            counter++;
        }
        if(flag == 1)   printf("%d %d\n",-1,-1);
        else            printf("%d %d\n",counter,startValue);
    }
    return 0;
}
