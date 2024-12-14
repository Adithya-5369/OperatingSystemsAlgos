#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void grep_com(const char *filename, const char *pattern) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s #include lscom_impl.c\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *pattern = argv[1];
    const char *filename = argv[2];
    grep_com(filename, pattern);

    return 0;
}

