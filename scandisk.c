/* SCAN Disk Scheduling Algo*/

#include <stdio.h>
#include <stdlib.h>

void scan(int requests[], int n, int head) {
    int total_seek_time = 0;
    int visited[n];
    printf("Starting from %d...\n", head);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = i + 1; j < n; j++)
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
    }
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            for (int j = i; j < n; j++) {
                if (!visited[j]) {
                    printf("Served to: %d\n", requests[j]);
                    visited[j] = 1;
                    total_seek_time += abs(requests[j] - head);
                    head = requests[j];
                }
            }
            if (head < requests[n - 1]) {
                if (!visited[n - 1]) {
                    printf("Served to: %d\n", requests[n - 1]);
                    visited[n - 1] = 1;
                    total_seek_time += abs(requests[n - 1] - head);
                    head = requests[n - 1];
                }
            }
            for (int j = n - 2; j >= 0; j--) {
                if (!visited[j]) {
                    printf("Served to: %d\n", requests[j]);
                    visited[j] = 1;
                    total_seek_time += abs(requests[j] - head);
                    head = requests[j];
                }
            }
            break;
        }
    }
    printf("Total Seek Time: %d\n", total_seek_time);
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
    scan(list, n, armh);
    return 0;
}