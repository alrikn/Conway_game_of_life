/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** just a place to hold structs so that my.h is'nt bloated
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <stdbool.h>
    #include <time.h>
    #include <stdio.h>

typedef struct core {
    int row;
    int col;
    bool went_wrong;
    FILE *file_map;
    int **array;
    int num_of_frames;
} core_t;

#endif
