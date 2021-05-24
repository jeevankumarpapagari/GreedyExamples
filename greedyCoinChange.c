#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    //Reading total number of denomination value
    int numberOfCoins;
    scanf("%d",&numberOfCoins);
    //Reading denomination values and storing into an array
    int coins[numberOfCoins], i, j, temp, amount, result = 0, duplicateAmount;
    for(i=0;i<numberOfCoins;i++)
        scanf("%d",&coins[i]);
    //Reading amount value
    scanf("%d",&amount);
    //Sorting all denominations in descending order
    for(i=0;i<numberOfCoins-1;i++)
    {
        for(j=i+1;j<numberOfCoins;j++)
        {
            if(coins[i] < coins[j])
            {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
    //Checking if amount value is greater than min dinomination value or not
    if(amount < coins[numberOfCoins-1])
    {
        printf("NUmber ofcoins required is: %d",0);
        return 0;
    }
    //Calculating min number of coins required
    i = 0;
    duplicateAmount = amount;
    while(amount && i<numberOfCoins)
    {
        temp = amount / coins[i];
        amount -= (temp * coins[i]);
        if(temp)    printf("Denomination Value: %d\tNumber required: %d\n",coins[i],temp);
        result += temp; 
        i++;
    }
    //Checking if we did get enough coins or not to make change 
    if(amount != 0)
    {
        printf("\nGiven denominations are not sufficient to make change. Remaining balance: %d",amount);
        return 0;
    }
    //Printing final output if met all conditions
    printf("\nTotal denominations are required is: %d",result);
    return 0;
}