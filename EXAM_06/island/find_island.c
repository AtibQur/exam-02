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

void print_num(int num)
{
    char nb[2049];
    int index = 0;
    while (num != 0)
    {
        nb[index++] = num % 10 + '0';
        num = num / 10;
    }
    for (int i = index - 1; i >= 0; i--)
        write(1, &nb[i], 1);
    write(1, "\n", 1);
}

void find_largest_island(char *file) {
    int fd, size, cols = 0;
    char map[BUFFERSIZE] = {0};

    if ((fd = open(file, O_RDONLY)) == -1 || !(size = read(fd, map, BUFFERSIZE))) return;

    map[size] = '\0';

    if (!get_size(map, &cols)) return;

    char count = '0';
    int maxIslandSize = 0, currentIslandSize = 0;

    for (int i = 0; i < size; i++) {
        if (map[i] == 'X') {
            currentIslandSize = 0;
            dfs(map, size, cols, i, count, &currentIslandSize);
            if (currentIslandSize > maxIslandSize) maxIslandSize = currentIslandSize;
            count++;
        }
    }

    print_num(maxIslandSize);
}

int main(int argc, char *argv[]) {
    if (argc != 2) return write(1, "\n", 1), 1;

    find_largest_island(argv[1]);
    return 0;
}
