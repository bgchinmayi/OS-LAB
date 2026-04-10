#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[20];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void fcfsScheduling(struct Process proc[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < proc[i].arrivalTime) {
            time = proc[i].arrivalTime;
        }
        proc[i].completionTime = time + proc[i].burstTime;
        proc[i].turnaroundTime = proc[i].completionTime - proc[i].arrivalTime;
        proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
        time += proc[i].burstTime;
    }
}

void printTable(struct Process proc[], int n, char queueName[]) {
    printf("\n--- %s Queue (FCFS Scheduling) ---\n", queueName);
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               proc[i].name,
               proc[i].arrivalTime,
               proc[i].burstTime,
               proc[i].completionTime,
               proc[i].turnaroundTime,
               proc[i].waitingTime);
    }
}

int main() {
    int sysCount, userCount;

    printf("Enter number of system processes: ");
    scanf("%d", &sysCount);
    struct Process sysProc[sysCount];

    for (int i = 0; i < sysCount; i++) {
        printf("\nEnter details for System Process %d\n", i + 1);
        printf("Name: ");
        scanf("%s", sysProc[i].name);
        printf("Arrival Time: ");
        scanf("%d", &sysProc[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &sysProc[i].burstTime);
    }

    printf("\nEnter number of user processes: ");
    scanf("%d", &userCount);
    struct Process userProc[userCount];

    for (int i = 0; i < userCount; i++) {
        printf("\nEnter details for User Process %d\n", i + 1);
        printf("Name: ");
        scanf("%s", userProc[i].name);
        printf("Arrival Time: ");
        scanf("%d", &userProc[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &userProc[i].burstTime);
    }


    fcfsScheduling(sysProc, sysCount);
    printTable(sysProc, sysCount, "System");


    fcfsScheduling(userProc, userCount);
    printTable(userProc, userCount, "User");

    return 0;
}
