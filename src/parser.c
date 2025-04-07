/*
** EPITECH PROJECT, 2025
** game of life
** File description:
** parse to map
*/

#include "my.h"
#include <string.h>

char *format(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '\n') {
            line[i] = '\0';
            return line;
        }
        i++;
    }
    return line;
}

static void get_col(core_t *core, char *line)
{
    line = format(line);
    core->col = strlen(line);
    if (core->col <= 0)
        core->went_wrong = true;
}

static int check_line_row(core_t *core)
{
    int num_of_line = 0;
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int first_size;

    read = getline(&line, &len, core->file_map);
    line = format(line);
    first_size = strlen(line);
    get_col(core, line);
    while (read != -1) {
        line = format(line);
        num_of_line++;
        if (strlen(line) != first_size)
            core->went_wrong = true;
        read = getline(&line, &len, core->file_map);
    }
    core->row = num_of_line;
    free(line);
    return num_of_line;
}

static int array_updater(core_t *core, int col, int row, char value)
{
    if (value == '.') {
        core->array[row][col] = 0;
        return 0;
    }
    if (value == 'X') {
        core->array[row][col] = 1;
        return 0;
    }
    exit(84);
    return 84;
}

int go_through(core_t *core)
{
    size_t len = 0;
    ssize_t read;
    char *line = NULL;
    int num_line = 0;
    int i = 0;

    fseek(core->file_map, SEEK_SET, 0);
    read = getline(&line, &len, core->file_map);
    while (read != -1) {
        line = format(line);
        while (line[i]) {
            array_updater(core, i, num_line, line[i]);
            i++;
        }
        i = 0;
        num_line++;
        read = getline(&line, &len, core->file_map);
    }
    free(line);
    return 0;
}

int parser(core_t *core)
{
    int row = check_line_row(core);
    int **map = malloc(sizeof(int *) * row);

    if (core->went_wrong)
        exit(84);
    for (int i = 0; i < core->row; i++) {
        map[i] = malloc(sizeof(int) * core->col);
    }
    core->array = map;
    go_through(core);
    if (core->went_wrong)
        exit(84);
    return 0;
}
