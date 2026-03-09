#include<stdio.h>
#include<limits.h>

int main()
{
    int n,i,time=0,remain;
    int at[20],bt[20],rt[20],wt[20],tat[20],ct[20];
    int smallest;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Process %d Arrival Time: ",i+1);
        scanf("%d",&at[i]);

        printf("Process %d Burst Time: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    remain=n;

    while(remain>0)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
        {
            time++;
            continue;
        }

        rt[smallest]--;
        time++;

        if(rt[smallest]==0)
        {
            remain--;

            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];

            avgwt+=wt[smallest];
            avgtat+=tat[smallest];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);

    return 0;
}
