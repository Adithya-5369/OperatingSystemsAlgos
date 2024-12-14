/*Round Robin CPU Scheduling Algo*/

#include <stdio.h>
#include <stdlib.h>

void calculateWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i]; // Copying burst times to remaining burst times

    int t = 0; // Current time
    while (1) {
        int done = 1; // To check if all processes are completed
        for (int i = 0 ; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is still a pending process
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void calculateTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    calculateWaitingTime(processes, n, bt, wt, quantum);
    calculateTurnaroundTime(processes, n, bt, wt, tat);
    // Display
    float total_wt = 0;
    printf("\nProcesses \t Burst Time \t Waiting Time \t Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n",i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time = ", (float)total_wt / (float)n);
}

int main() {
    int processes[] = {1, 2, 3,4,5}; // Process IDs
    int n = sizeof(processes) / sizeof(processes[0]);
    // Burst time of processes
    int burst_time[] = {20,5,6,10,7};
    // Time quantum
    int quantum = 5;
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}

