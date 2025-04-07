/*
** EPITECH PROJECT, 2025
** duo-stumper1
** File description:
** just the main
*/


#include "my.h"
#include "struct.h"

bool is_num(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

static void initializer(char **argv, core_t *core)
{
    core->num_of_frames = -1;
    core->file_map = fopen(argv[1], "r");
    if (!core->file_map)
        exit(84);
    if (!is_num(argv[2]))
        exit(84);
    core->num_of_frames = atoi(argv[2]);
    if (core->num_of_frames < 0)
        exit(84);
}

void run_frames(core_t *core)
{
    for (int i = 0; i < core->num_of_frames; i++) {
        updater(core);
    }
    printer(core);
}

void freer(core_t *core)
{
    fclose(core->file_map);
    free_int_array(core->array, core->row);
}

int main(int argc, char **argv)
{
    core_t core = {0};

    if (argc != 3)
        return 84;
    initializer(argv, &core);
    parser(&core);
    run_frames(&core);
    freer(&core);
    if (core.went_wrong)
        return 84;
    return 0;
}
