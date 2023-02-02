/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

void free_all(char *buffer, sbk *sbk1, char *map2)
{
    free(buffer);
    free(sbk1);
    free(map2);
}
