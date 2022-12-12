#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int at;
    int bt;
    int tat;
    int wt;
};

int compare(const void *a, const void *b) {
    int at1 = (*(const struct process *)a).at;
    int at2 = (*(const struct process *)b).at;
    if (at1 <= at2) return -1;
    return 1;
}

void printProcesses(struct process processes[], int size) {
    printf("| PROCESS ID | ARRIVAL TIME | BURST TIME | TURNAROUND TIME | WAITING TIME |\n");
    for (int i = 0; i < size; ++i) {
        printf("|%6d%6s|%7d%7s|%6d%6s|%9d%8s|%7d%7s|\n",
               processes[i].pid, "",
               processes[i].at, "",
               processes[i].bt, "",
               processes[i].tat, "",
               processes[i].wt, "");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    printf("Enter the arrival and burst time of corresponding processes:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &processes[i].at, &processes[i].bt);
        processes[i].pid = i;
    }

    qsort(processes, n, sizeof(struct process), compare);

    int timePassed = processes[0].at;
    for (int i = 0; i < n; ++i) {
        if (processes[i].at > timePassed)
            timePassed += processes[i].at - timePassed;
        timePassed += processes[i].bt;
        processes[i].tat = timePassed - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }

    printProcesses(processes, n);

    int averageTurnAroundTime = 0, averageWaitingTime = 0;
    for (int i = 0; i < n; ++i) {
        averageTurnAroundTime += processes[i].tat;
        averageWaitingTime += processes[i].wt;
    }

    printf("Average Turnaround Time = %.2lf\n", (double)averageTurnAroundTime / n);
    printf("Average Waiting Time = %.2lf\n", (double)averageWaitingTime / n);
    return 0;
}