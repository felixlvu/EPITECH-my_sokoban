/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

void moins_len(sbk *sbk1)
{
    int temp = sbk1->poss_player;
    int count = 0;
    while (sbk1->map[temp] != '\n') {
        temp = temp - 1;
    }
    temp = temp - 1;
    while (temp != 0 && sbk1->map[temp] != '\n') {
        temp = temp - 1;
        count++;
    }
    sbk1->len_moins = count + 1;
}

void plus_len(sbk *sbk1)
{
    int temp = sbk1->poss_player;
    int count = 0;
    while (sbk1->map[temp] != '\n') {
        temp = temp + 1;
    }
    temp = temp + 1;
    while (sbk1->map[temp] != '\n') {
        temp = temp + 1;
        count++;
    }
    sbk1->len_plus = count + 1;
}
