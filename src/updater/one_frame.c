/*
** EPITECH PROJECT, 2025
** duo_stumper_2
** File description:
** one_frame
*/

#include "my.h"
#include "struct.h"

static const int directions[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

int **make_new(core_t *core)
{
    int **new_map = malloc(sizeof(int *) * core->row);

    for (int i = 0; i < core->row; i++) {
        new_map[i] = malloc(sizeof(int) * core->col);
    }
    return new_map;
}

static int count_cells(core_t *core, int x, int y)
{
    int num_of_cell = 0;
    int x_check = 0;
    int y_check = 0;

    for (int i = 0; i < 8; i++) {
        y_check = y + directions[i][0];
        x_check = x + directions[i][1];
        if ((y_check < core->row && y_check >= 0) &&
        (x_check < core->col && x_check >= 0) &&
        (core->array[y_check][x_check] == 1))
            num_of_cell += 1;
    }
    return num_of_cell;
}

static int update_new(core_t *core, int **new_map, int x, int y)
{
    int num_of_cell = count_cells(core, x, y);

    if (num_of_cell <= 1)
        new_map[y][x] = 0;
    if (num_of_cell == 2)
        new_map[y][x] = core->array[y][x];
    if (num_of_cell == 3)
        new_map[y][x] = 1;
    if (num_of_cell > 3)
        new_map[y][x] = 0;
    return num_of_cell;
}

static void go_through(core_t *core, int **new_map)
{
    for (int y = 0; y < core->row; y++) {
        for (int x = 0; x < core->col; x++) {
            update_new(core, new_map, x, y);
        }
    }
}

int updater(core_t *core)
{
    int **old_map = core->array;
    int **new_map = make_new(core);

    go_through(core, new_map);
    free_int_array(old_map, core->row);
    core->array = new_map;
    return 0;
}
