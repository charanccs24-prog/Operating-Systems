#include <stdio.h>

// Structure for process
struct process {
    int pid, at, bt, type;
    int ct, tat, wt, start;
};

// Function to sort by Arrival Time (FCFS order)
void sortByAT(struct process p[], int n) {
    int i, j;
    struct process temp;

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// FCFS execution
void execute(struct process q[], int n, int *time) {
    int i;

    for(i = 0; i < n; i++) {
        if(*time < q[i].at)
            *time = q[i].at;

        q[i].start = *time;
        *time += q[i].bt;

        q[i].ct = *time;
        q[i].tat = q[i].ct - q[i].at;
        q[i].wt = q[i].tat - q[i].bt;
    }
}

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n], sys[n], user[n];
    int sysCount = 0, userCount = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i+1);
        printf("PID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Type (0=System, 1=User): ");
        scanf("%d", &p[i].type);
    }

    // Step 1: Separate into queues
    for(i = 0; i < n; i++) {
        if(p[i].type == 0)
            sys[sysCount++] = p[i];
        else
            user[userCount++] = p[i];
    }

    // Step 2: Sort both queues by Arrival Time
    sortByAT(sys, sysCount);
    sortByAT(user, userCount);

    int time = 0;

    // Step 3: Execute System Queue
    execute(sys, sysCount, &time);

    // Step 4: Execute User Queue
    execute(user, userCount, &time);

    // Step 5: Display Results
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

    for(i = 0; i < sysCount; i++) {
        printf("%d\t%d\t%d\t0\t%d\t%d\t%d\n",
            sys[i].pid, sys[i].at, sys[i].bt,
            sys[i].ct, sys[i].tat, sys[i].wt);
    }

    for(i = 0; i < userCount; i++) {
        printf("%d\t%d\t%d\t1\t%d\t%d\t%d\n",
            user[i].pid, user[i].at, user[i].bt,
            user[i].ct, user[i].tat, user[i].wt);
    }

    return 0;
}
