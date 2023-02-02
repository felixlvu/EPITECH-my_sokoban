/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

void check_valid_map(sbk *sbk1)
{
    int P = 0, O = 0, X = 0;

    for ( int count = 0; sbk1->map[count] != '\0'; count++) {
        if (sbk1->map[count] == 'P') {
            sbk1->map2[count] = ' ';
            sbk1->poss_player = count;
            sbk1->save_poss = count;
            P++;
        }
        if (sbk1->map[count] == 'O')
            O++;
        if (sbk1->map[count] == 'X') {
            sbk1->map2[count] = ' ';
            X++;
        }
    }
    if (O != X)
        exit (84);
    if (P != 1)
        exit (84);
}
