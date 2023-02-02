/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

int my_strlen_sbk(char const *str)
{
    int x = 0;
    while (str[x] != '\n') {
        x++;
    }
    return x + 1;
}
