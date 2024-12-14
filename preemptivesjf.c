/* Preemptive Shortest Job First CPU Scheduling Algo*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int main() {
    int at[MAX]; // Arrival Times
    int bt[MAX]; // Burst Times
    int temp[MAX]; // Temporary Array
    int wt[MAX]; // Waiting Times
    int tat[MAX]; // Turnaround Times
    int p[MAX]; // Process IDs
    int i, j, smallest, total_wt = 0, total_tat = 0, count = 0, time, limit;
    float average_waiting_time;

    printf("Enter Number of Processes: ");
    scanf("%d", &limit);

    if (limit > MAX) {
        printf("Limit exceeds maximum allowed processes (%d).\n", MAX);
        return 1;
    }

    printf("\nEnter Details of %d Processes:\n", limit);
    for (i = 0; i < limit; i++) {
        printf("Enter Arrival Time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        p[i] = i + 1;
    }

    int remaining_bt[MAX];
    for (i = 0; i < limit; i++) {
        remaining_bt[i] = bt[i];
    }

    // Preemptive SJF scheduling
    for (time = 0; count != limit; time++) {
        smallest = -1;
        int min_bt = INT_MAX;
        
        for (i = 0; i < limit; i++) {
            if (at[i] <= time && remaining_bt[i] > 0 && remaining_bt[i] < min_bt) {
                min_bt = remaining_bt[i];
                smallest = i;
            }
        }

        if (smallest != -1) {
            remaining_bt[smallest]--;
            if (remaining_bt[smallest] == 0) {
                count++;
                tat[smallest] = time + 1 - at[smallest];
                wt[smallest] = tat[smallest] - temp[smallest];
                total_wt += wt[smallest];
                total_tat += tat[smallest];
            }
        }
    }

    // Display
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < limit; i++) {
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", p[i], temp[i], wt[i], tat[i]);
    }

    // Average Wait Time Calculation
    average_waiting_time = (float)total_wt / limit;
    printf("\nAverage Waiting Time: %f\n", average_waiting_time);

    return 0;
}
