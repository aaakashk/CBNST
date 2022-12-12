#include <limits.h>
#include <stdio.h>
#include <string.h>

struct process {
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;  // remaining Time
};

int nextShortestJobIndex(struct process[], int, int);
void printProcesses(struct process[], int);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    memset(processes, 0, sizeof(processes));

    printf("Enter arrival time and burst time of each process:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &processes[i].at, &processes[i].bt);
        processes[i].rt = processes[i].bt;
    }

    // calculating minimum arrival Time
    int timePassed = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (processes[i].at < timePassed)
            timePassed = processes[i].at;
    }

    int timeQuanta;
    printf("Enter time quanta: ");
    scanf("%d", &timeQuanta);

    int complete = 0;
    while (complete != n) {
        int k = nextShortestJobIndex(processes, n, timePassed);
        if (processes[k].rt != 0) {
            int min = processes[k].rt < timeQuanta ? processes[k].rt : timeQuanta;
            processes[k].rt -= min;
            timePassed += min - timeQuanta;
        }
        if (processes[k].rt == 0) {
            ++complete;
            processes[k].ct = timePassed + timeQuanta;
        }
        timePassed += timeQuanta;
    }

    for (int i = 0; i < n; ++i) {
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }

    printProcesses(processes, n);

    int averageWaitingTime = 0, averageTurnAroundTime = 0;
    for (int i = 0; i < n; ++i) {
        averageTurnAroundTime += processes[i].tat;
        averageWaitingTime += processes[i].wt;
    }

    printf("Average TurnAround Time = %.2lf\n", (double)averageTurnAroundTime / n);
    printf("Average Waiting Time = %.2lf\n", (double)averageWaitingTime / n);
    return 0;
}

int nextShortestJobIndex(struct process processes[], const int n, const int timePassed) {
    int j = 0, count = 0;
    int readyQueue[n];
    memset(readyQueue, 0, sizeof(readyQueue));
    for (int i = 0; i < n; ++i) {
        if (processes[i].rt > 0 && processes[i].at <= timePassed) {
            readyQueue[j++] = i;
            count++;
        }
    }

    int shortestRemaingingTime = INT_MAX, index = 0;
    for (int i = 0; i < count; ++i) {
        if (processes[readyQueue[i]].rt < shortestRemaingingTime) {
            shortestRemaingingTime = processes[readyQueue[i]].rt;
            index = readyQueue[i];
        }
    }
    return index;
}

void printProcesses(struct process processes[], int size) {
    printf("| ARRIVAL TIME | BURST TIME | COMPLETION TIME | TURNAROUND TIME | WAITING TIME |\n");
    for (int i = 0; i < size; ++i) {
        printf("|%7d%7s|%6d%6s|%8d%8s|%9d%8s|%7d%7s|\n",
               processes[i].at, "",
               processes[i].bt, "",
               processes[i].ct, "",
               processes[i].tat, "",
               processes[i].wt, "");
    }
    printf("\n");
}