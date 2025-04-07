/*
** EPITECH PROJECT, 2024
** fake_my_hunter
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H
    #include <stdlib.h>
    #include "struct.h"
    #include <unistd.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <string.h>
    #include <string.h>
    #include <sys/types.h>
    #include <time.h>
    #include <sys/wait.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>

    #define PATH "/etc/passwd"
    #define MAX_PATH_LEN 64
    #define MAX_LOOP_INPUT 2048

int parser(core_t *core);
void printer(core_t *core);
int free_int_array(int **array, int rows);
int updater(core_t *core);
#endif
