#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int compare(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int numberOfCupCakes;
    scanf("%d",&numberOfCupCakes);

    int calorieCountOfEachCupCake[numberOfCupCakes], i;
    for(i=0;i<numberOfCupCakes;i++)
        scanf("%d",&calorieCountOfEachCupCake[i]);

    qsort(calorieCountOfEachCupCake,numberOfCupCakes,sizeof(int),compare);

    int minimumNumberOfMilesToWalk = 0, j = 0;
    for(i=numberOfCupCakes-1;i>=0;i--,j++)
        minimumNumberOfMilesToWalk += calorieCountOfEachCupCake[i] * pow(2,j);

    printf("%d",minimumNumberOfMilesToWalk);
    return 0;
}