#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void list_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const char *path = (argc == 2) ? argv[1] : ".";
    list_directory(path);

    return 0;
}
