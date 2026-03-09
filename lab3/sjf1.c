#include<stdio.h>

int main()
{
    int n,i,j,time=0,min,idx;
    int at[20],bt[20],wt[20],tat[20],ct[20],completed[20]={0};
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Process %d Arrival Time: ",i+1);
        scanf("%d",&at[i]);

        printf("Process %d Burst Time: ",i+1);
        scanf("%d",&bt[i]);
    }

    int done=0;

    while(done<n)
    {
        min=9999;
        idx=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0 && bt[i]<min)
            {
                min=bt[i];
                idx=i;
            }
        }

        if(idx!=-1)
        {
            time+=bt[idx];
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];

            completed[idx]=1;
            done++;
        }
        else
        {
            time++;
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);

    return 0;
}
