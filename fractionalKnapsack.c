#include<stdio.h>
int main(void)
{
    //Reading value of total number of objects
    int n;
    scanf("%d",&n);
    //Reading object values into separate arrays and calculating ratio values
    float profit[n], weight[n], profitByWeight[n], temp, capacity, totalProfit = 0.0;
    int i, j;
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&profit[i],&weight[i]);
        profitByWeight[i] = profit[i] / weight[i];
    }
    //Reading total capacity value
    scanf("%f",&capacity);
    //Sorting ratio values in descending order respectively profit and weight
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(profitByWeight[i] < profitByWeight[j])
            {
                temp = profitByWeight[i];
                profitByWeight[i] = profitByWeight[j];
                profitByWeight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
    //Calculation maximum profit
    i = 0;
    while(i<n)
    {
        if(weight[i] > capacity)
            break;
        totalProfit += profit[i];
        capacity -= weight[i];
        i++;
    }
    if(i<n)
        totalProfit += (capacity/weight[i])*profit[i]; 
    //Printing maximum profit value
    printf("Maximum Profit value: %f",totalProfit);
    return 0;
}