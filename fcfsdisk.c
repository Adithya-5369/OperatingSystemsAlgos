/* First Come First Serve Disk Scheduling Algo*/

#include <stdio.h>
#include <stdlib.h>

void fcfs(int a[], int n, int ah) {
    int dat = 0;
    printf("Starting from: %d...\n", ah);
    int r = ah;
    for (int i = 0; i < n; i++) {
        printf("Served to: %d\n", a[i]);
        dat += abs(a[i] - r);
        r = a[i];
    }
    printf("Total Seek Time: %d\n", dat);
}

void traverse(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int list[n];
    printf("Enter the cylinder numbers for disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &list[i]);
    }
    int armh;
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &armh);
    printf("Requests to be served: ");
    traverse(list, n);
    fcfs(list, n, armh);
    return 0;
}