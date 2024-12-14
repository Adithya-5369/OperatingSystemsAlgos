/* First Come First Serve CPU Scheduling Algo*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void completionTime(int CT[],int BT[],int n){
    CT[0] = BT[0];
    for(int i=1;i<5;i++){
        CT[i] = BT[i] + CT[i-1];
    }
}

void turnaroundTime(int CT[],int AT[],int TAT[], int n){
   for(int j=0;j<5;j++){
        TAT[j] = CT[j] - AT[j];
   }
}

void waitTime(int WT[],int TAT[], int BT[], int n){
    for(int k=0;k<5;k++){
         WT[k] = TAT[k] - BT[k];
    }
}

void Display1(int WT[],int TAT[],int P[], int CT[],int BT[],int AT[],int n){
    printf("\nProcess \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turnaround Time");
    for(int i=0;i<n;i++)
    {
        printf("\np%d\t\t %d\t\t %d\t\t %d\t\t           %d\t\t\t             %d\t\t\t",P[i],AT[i],BT[i],CT[i],WT[i],TAT[i]);
    }
}

int main(){
    int processes[] = {1,2,3,4,5}; //Processes
    int n = sizeof processes / sizeof processes[0]; //Number of Processes
    int arrival_time[] = {0,1,3,5,6}; //Arrival Times
    int burst_time[] = {20,5,6,10,7}; //Burst Times
    int completion_time[n];
    int turn_around_time[n];
    int wait_time[n];
    // Completion Time Calc.
    completionTime(completion_time,burst_time,n);
    // Turn Around Time Calc.
    turnaroundTime(completion_time,arrival_time,turn_around_time,n);
    // Wait Time Calc.
    waitTime(wait_time,turn_around_time,burst_time,n);
    // Display
    Display1(wait_time,turn_around_time,processes,completion_time,burst_time,arrival_time,n);
    // Avg Wait Time Calc.
    float avg_waitTime;
    for(int a=0; a<n; a++){
        avg_waitTime += wait_time[a];
    }
    float avgwait_Time = avg_waitTime/5;
    printf("\nAverage Wait Time: %f\n", avgwait_Time);
    return 0;
}
