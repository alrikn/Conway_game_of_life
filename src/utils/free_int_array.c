/*
** EPITECH PROJECT, 2025
** duo stumper 2
** File description:
** free_array
*/

#include <stdlib.h>

int free_int_array(int **array, int rows)
{
    if (!array)
        return 1;
    for (int i = 0; i < rows; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
    array = NULL;
    return 0;
}
