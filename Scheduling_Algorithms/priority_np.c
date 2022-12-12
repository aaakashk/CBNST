#include <limits.h>
#include <stdio.h>
#include <string.h>

struct process {
    int at;
    int bt;
    int priority;
    int tat;
    int wt;
    int isComplete;
};

int nextSmallestPriorityIndex(struct process[], int, int);
void printProcesses(struct process[], int);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    memset(processes, 0, sizeof(processes));

    printf("Enter arrival time, burst time and priority of each process:\n");
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &processes[i].at, &processes[i].bt, &processes[i].priority);

    // calculating minimum arrival Time
    int timePassed = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (processes[i].at < timePassed)
            timePassed = processes[i].at;
    }

    for (int i = 0; i < n; ++i) {
        int k = nextSmallestPriorityIndex(processes, n, timePassed);
        timePassed += processes[k].bt;
        processes[k].tat = timePassed - processes[k].at;
        processes[k].wt = processes[k].tat - processes[k].bt;
        processes[k].isComplete = 1;
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

int nextSmallestPriorityIndex(struct process processes[], const int n, const int timePassed) {
    int j = 0, count = 0;
    int readyQueue[n];
    memset(readyQueue, 0, sizeof(readyQueue));
    for (int i = 0; i < n; ++i) {
        if (!processes[i].isComplete && processes[i].at <= timePassed) {
            readyQueue[j++] = i;
            count++;
        }
    }

    int smallestPriority = INT_MAX, index = 0;
    for (int i = 0; i < count; ++i) {
        if (processes[readyQueue[i]].priority < smallestPriority) {
            smallestPriority = processes[readyQueue[i]].priority;
            index = readyQueue[i];
        }
    }
    return index;
}

void printProcesses(struct process processes[], int size) {
    printf("| ARRIVAL TIME | BURST TIME | PRIORITY | TURNAROUND TIME | WAITING TIME |\n");
    for (int i = 0; i < size; ++i) {
        printf("|%7d%7s|%6d%6s|%5d%5s|%9d%8s|%7d%7s|\n",
               processes[i].at, "",
               processes[i].bt, "",
               processes[i].priority, "",
               processes[i].tat, "",
               processes[i].wt, "");
    }
    printf("\n");
}