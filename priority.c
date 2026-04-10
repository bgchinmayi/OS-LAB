#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int pr;
    int wt;
    int tat;
    int ct;
    int done;
};

int main() {
    int n;
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
        printf("Enter priority of process %d (lower = higher priority): ", p[i].pid);
        scanf("%d", &p[i].pr);
        p[i].done = 0;
    }

    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = 9999;


        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].done == 0) {
                if (p[i].pr < highest_priority) {
                    highest_priority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].done = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
