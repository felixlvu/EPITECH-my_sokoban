/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

void move_up(sbk *sbk1, int len)
{
    if (sbk1->map[sbk1->poss_player - sbk1->len_moins] == ' '
    || sbk1->map[sbk1->poss_player - sbk1->len_moins] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player - sbk1->len_moins] = 'P';
        sbk1->poss_player = sbk1->poss_player - sbk1->len_moins;
    } else if (sbk1->map[sbk1->poss_player - sbk1->len_moins] == 'X'
    && sbk1->map[sbk1->poss_player - (sbk1->len_moins * 2)] == ' '
    || sbk1->map[sbk1->poss_player - (sbk1->len_moins * 2)] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player - sbk1->len_moins] = 'P';
        sbk1->map[sbk1->poss_player - (sbk1->len_moins * 2)] = 'X';
        sbk1->poss_player = sbk1->poss_player - sbk1->len_moins;
    }
}

void move_down(sbk *sbk1, int len)
{
    if (sbk1->map[sbk1->poss_player + sbk1->len_plus] == ' '
    || sbk1->map[sbk1->poss_player + sbk1->len_plus] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player + sbk1->len_plus] = 'P';
        sbk1->poss_player = sbk1->poss_player + sbk1->len_plus;
    } else if (sbk1->map[sbk1->poss_player + sbk1->len_plus] == 'X'
    && sbk1->map[sbk1->poss_player + (sbk1->len_plus * 2)] == ' '
    || sbk1->map[sbk1->poss_player + (sbk1->len_plus * 2)] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player + sbk1->len_plus] = 'P';
        sbk1->map[sbk1->poss_player + (sbk1->len_plus * 2)] = 'X';
        sbk1->poss_player = sbk1->poss_player + sbk1->len_plus;
    }
}

void move_left(sbk *sbk1, int len)
{
    if (sbk1->map[sbk1->poss_player - 1] == ' '
    || sbk1->map[sbk1->poss_player - 1] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player - 1] = 'P';
        sbk1->poss_player = sbk1->poss_player - 1;
    } else if (sbk1->map[sbk1->poss_player - 1] == 'X'
    && sbk1->map[sbk1->poss_player - 2] == ' '
    || sbk1->map[sbk1->poss_player - 2] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player - 1] = 'P';
        sbk1->map[sbk1->poss_player - 2] = 'X';
        sbk1->poss_player = sbk1->poss_player - 1;
    }
}

void move_right(sbk *sbk1, int len)
{
    if (sbk1->map[sbk1->poss_player + 1] == ' '
    || sbk1->map[sbk1->poss_player + 1] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player + 1] = 'P';
        sbk1->poss_player = sbk1->poss_player + 1;
    } else if (sbk1->map[sbk1->poss_player + 1] == 'X'
    && sbk1->map[sbk1->poss_player + 2] == ' '
    || sbk1->map[sbk1->poss_player + 2] == 'O') {
        sbk1->map[sbk1->poss_player] = sbk1->map2[sbk1->poss_player];
        sbk1->map[sbk1->poss_player + 1] = 'P';
        sbk1->map[sbk1->poss_player + 2] = 'X';
        sbk1->poss_player = sbk1->poss_player + 1;
    }
}

void move_map(sbk *sbk1, int k)
{
    int len = my_strlen_sbk(sbk1->map);
    sbk1->len = len;
    if (k == KEY_LEFT && sbk1->map[sbk1->poss_player - 1] != '#')
        move_left(sbk1, len);
    if (k == KEY_RIGHT && sbk1->map[sbk1->poss_player + 1] != '#')
        move_right(sbk1, len);
    moins_len(sbk1);
    if (k == KEY_UP && sbk1->map[sbk1->poss_player - sbk1->len_moins] != '#')
        move_up(sbk1, len);
    plus_len(sbk1);
    if (k == KEY_DOWN && sbk1->map[sbk1->poss_player + sbk1->len_plus] != '#')
        move_down(sbk1, len);
    if (k == ' ') {
        sbk1->map = open_skb(sbk1->arv1, sbk1->buffer);
        sbk1->poss_player = sbk1->save_poss;
    }
}
