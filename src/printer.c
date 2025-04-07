/*
** EPITECH PROJECT, 2025
** game of life
** File description:
** prints an grid of integers
*/

#include "my.h"

static void print_specific(int value)
{
    if (value == 1)
        printf("X");
    if (value == 0)
        printf(".");
    if (value != 1 && value != 0)
        printf("?");
}

void printer(core_t *core)
{
    int col = 0;
    int row = 0;

    while (row < core->row) {
        while (col < core->col) {
            print_specific(core->array[row][col]);
            col++;
        }
        col = 0;
        row++;
        printf("\n");
    }
}
