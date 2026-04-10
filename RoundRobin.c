#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    int completed;
};

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int i;
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time of process %d: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Enter burst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].wt = 0;
        p[i].tat = 0;
        p[i].completed = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int time = 0;
    int done;

    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (p[i].rt > 0 && p[i].at <= time) {
                done = 0;
                if (p[i].rt > quantum) {
                    time += quantum;
                    p[i].rt -= quantum;
                } else {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt - p[i].at;
                    p[i].rt = 0;
                    p[i].tat = p[i].wt + p[i].bt;
                    p[i].completed = 1;
                }
            }
        }
        if (done == 1)
            break;
    }

    float total_wt = 0, total_tat = 0;
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

