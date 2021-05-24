#include<stdio.h>
#include<stdlib.h>
//Declaring job structure
struct job
{
    int jobId;
    float profit;
    int deadline;
};
int main(void)
{
    //Reading n value into the program
    int n,i,j;
    scanf("%d",&n);
    //Declaring array of structure
    struct job jobList[n],temp;
    //Reading data into array of structure
    for(i=0;i<n;i++)
        scanf("%d%f%d",&jobList[i].jobId, &jobList[i].profit, &jobList[i].deadline);
    //Sorting data based on profit in descending order
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(jobList[i].profit < jobList[j].profit)
            {
                temp = jobList[i];
                jobList[i] = jobList[j];
                jobList[j] = temp;
            }
        }
    }
    //Process to find max deadline in the given input
    int maxDeadline = jobList[0].deadline;
    for(i=0;i<n;i++)
    {
        if(maxDeadline < jobList[i].deadline)
            maxDeadline = jobList[i].deadline;
    }
    //Declaring final job sequence list
    int jobSequenceList[maxDeadline];
    float totalProfit = 0.0;
    memset(jobSequenceList,0,maxDeadline*sizeof(int));
    //Process to finalize the list and find maximum profit value
    for(i=0;i<n;i++)
    {
        if(jobSequenceList[jobList[i].deadline-1] == 0)
        {
            jobSequenceList[jobList[i].deadline-1] = jobList[i].jobId;
            totalProfit += jobList[i].profit;
        }
        else
        {
            int k = jobList[i].deadline-1;
            while(--k >= 0)
            {
                if(jobSequenceList[k] == 0)
                {
                    jobSequenceList[k] = jobList[i].jobId;
                    totalProfit += jobList[i].profit;
                    break;
                }  
            }
        }
    }
    //Displaying job sequencing and Maximum profit
    printf("\nJob sequencing order:\n");
    for(i=0;i<maxDeadline;i++)
    {
        if(jobSequenceList[i] != 0)
            printf("Job Id: %d\n",jobSequenceList[i]);
    }
    printf("Maximum Profit value is: %f",totalProfit);
}