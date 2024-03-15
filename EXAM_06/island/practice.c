#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFERSIZE 1024 * 1024

void dfs(char map[BUFFERSIZE], int size, int cols, int i, char count, int *islandSize) {
    if (i < 0 || i >= size || map[i] != 'X') return;

    map[i] = count;
    (*islandSize)++;

    dfs(map, size, cols, i - cols, count, islandSize);
    dfs(map, size, cols, i + cols, count, islandSize);
    dfs(map, size, cols, i - 1, count, islandSize);
    dfs(map, size, cols, i + 1, count, islandSize);
}

bool get_size(char map[BUFFERSIZE], int *cols) {
    int same_len = 1;

    for (int i = 0; map[i]; i++) {
        if (!(map[i] == 'X' || map[i] == '.' || map[i] == '\n')) return false;

        if (map[i] == '\n') {
            if (!(*cols)) (*cols) = same_len;
            if (*cols != same_len) return false;
            same_len = 0;
        }
        same_len++;
    }
    return true;
}