/* Shortest Seek Time First Disk Scheduling Algo*/

#include <stdio.h>
#include <stdlib.h>

void sstf(int a[], int n, int ah) {
    int dat = 0;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    printf("Starting from: %d...\n", ah);
    int r = ah;
    for (int i = 0; i < n; i++) {
        int closest = -1;
        int closest_index = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (closest == -1 || abs(a[j] - ah) < closest)) {
                closest = abs(a[j] - ah);
                closest_index = j;
            }
        }
        visited[closest_index] = 1;
        ah = a[closest_index];
        printf("Served to: %d\n", ah);
        dat += abs(a[closest_index] - r);
        r = a[closest_index];
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
    sstf(list, n, armh);

    return 0;
}