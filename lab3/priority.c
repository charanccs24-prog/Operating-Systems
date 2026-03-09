#include<stdio.h>

struct process
{
    int pid, at, bt, pr, ct, tat, wt, completed;
};

int main()
{
    int n,i,time=0,completed=0,highest;
    float avgwt=0,avgtat=0;
    struct process p[10],temp;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);
        p[i].pid=i+1;

        printf("Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);

        p[i].completed=0;
    }

    while(completed<n)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0)
            {
                if(highest==-1 || p[i].pr < p[highest].pr)
                highest=i;
            }
        }

        if(highest!=-1)
        {
            time += p[highest].bt;
            p[highest].ct = time;
            p[highest].tat = p[highest].ct - p[highest].at;
            p[highest].wt = p[highest].tat - p[highest].bt;

            avgwt += p[highest].wt;
            avgtat += p[highest].tat;

            p[highest].completed=1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    return 0;
}
