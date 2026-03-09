#include<stdio.h>

int main()
{
    int n,i,time=0,remain,smallest;
    int at[10],bt[10],rt[10],pr[10];
    int wt=0,tat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    remain=n;

    while(remain!=0)
    {
        smallest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(smallest==-1 || pr[i] < pr[smallest])
                smallest=i;
            }
        }

        if(smallest!=-1)
        {
            rt[smallest]--;
            time++;

            if(rt[smallest]==0)
            {
                remain--;

                int finish=time;

                wt += finish - at[smallest] - bt[smallest];
                tat += finish - at[smallest];
            }
        }
        else
        {
            time++;
        }
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time = %.2f", (float)tat/n);

    return 0;
}
