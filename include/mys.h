/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MYS_H
    #define MYS_H

typedef struct {
    int poss_player;
    int save_poss;
    int len;
    int len_plus;
    int len_moins;
    int size;
    int event;
    char *map;
    char *map2;
    char **arv1;
    char *buffer;
}sbk;

    #include <ncurses.h>
    #include <curses.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <unistd.h>

    int main(int arc, char **arv);
    int my_strlen_sbk(char const *str);
    void moins_len(sbk *sbk1);
    void plus_len(sbk *sbk1);
    void check_lose(sbk *sbk1);
    void check_win(sbk *sbk1);
    void move_map(sbk *sbk1, int k);
    void check_valid_map(sbk *sbk1);
    void free_all(char *buffer, sbk *sbk1, char *map2);
    char *open_skb(char **arv, char *buffer);
#endif
