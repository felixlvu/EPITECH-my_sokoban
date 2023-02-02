/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

int check_win_next(sbk *sbk1, int count)
{
    if (sbk1->map2[count] == 'O')
        return 1;
    return 0;
}

void check_win(sbk *sbk1)
{
    int O = 0, X = 0;

    for (int count = 0; sbk1->map[count] != '\0'; count++) {
        if (sbk1->map2[count] == 'O')
            O++;
    }
    for (int count = 0; sbk1->map[count] != '\0'; count++) {
        if (sbk1->map[count] == 'X') {
            X += check_win_next(sbk1, count);
        }
    }
    if (O == X)
        sbk1->event = 1;
}

void check_lose_x(int count, sbk *sbk1)
{
    int htag = 0;
    if (sbk1->map[count + 1] == '#' && sbk1->map[count - sbk1->len] == '#'
    && sbk1->map2[count] != 'O')
        htag++;
    if (sbk1->map[count - 1] == '#' && sbk1->map[count - sbk1->len] == '#'
    && sbk1->map2[count] != 'O')
        htag++;
    if (sbk1->map[count - 1] == '#' && sbk1->map[count + sbk1->len] == '#'
    && sbk1->map2[count] != 'O')
        htag++;
    if (sbk1->map[count + 1] == '#' && sbk1->map[count + sbk1->len] == '#'
    && sbk1->map2[count] != 'O')
        htag++;
    if (htag >= 1)
        sbk1->event = 1;
}

void check_lose(sbk *sbk1)
{
    for (int count = 0; sbk1->map[count] != '\0'; count++) {
        if (sbk1->map[count] == 'X')
            check_lose_x(count, sbk1);
    }
}
