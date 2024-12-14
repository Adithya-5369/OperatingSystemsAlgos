/*Non Preemptive Shortest Job First CPU Scheduling Algo*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int bt[20];
    int p[20];
    int wt[20];
    int tat[20];
    int i,j,n,total=0,totalT=0,pos,temp;
    float avg_wt;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++){
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    //Sorting of burst times
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    //Finding the waiting time of all the processes
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    // Display
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        totalT+=tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    //Average waiting time
    avg_wt=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
}
