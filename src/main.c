/*
** EPITECH PROJECT, 2022
** csfml
** File description:
** csfml
*/

#include "my.h"
#include "mys.h"

int flag_h(int arc, char **arv)
{
    if (arv[1][0] == '-' && arv[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("     ./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("     map file representing the warehouse map, \n");
        my_printf("containing ‘#’ for walls,\n");
        my_printf("         ‘P’ for the player, ‘X’ for boxes");
        my_printf(" and ‘O’ for storage locations.\n");
        exit (0);
    } else if (arv[1][0] == '-' && arv[1][1] != 'h'){
        exit (84);
    }
    return 0;
}

void test_error(int arc, sbk *sbk1)
{
    if (arc != 2)
        exit(84);
    if (arc == 1)
        exit(84);
    for (int count = 0; sbk1->map[count] != '\0'; count++) {
        if (sbk1->map[count] != ' ' && sbk1->map[count] != '\n'
        && sbk1->map[count] != '#' && sbk1->map[count] != 'X'
        && sbk1->map[count] != 'O' && sbk1->map[count] != 'P')
            exit (84);
    }
}

char *open_skb(char **arv, char *buffer)
{
    int file = open(arv[1], O_RDONLY);
    int len = 0, offset = 0;
    struct stat sfile;
    stat (arv[1], &sfile);

    if (file == -1)
        exit (84);

    while ((len = read(file, (buffer) + offset,
    (sfile.st_size + 1) - offset)) > 0) {
        offset = offset + len;
    }
    (buffer)[offset] = '\0';
    close(file);
    return buffer;
}

int main_sokoban(char **arv, sbk *sbk1)
{
    WINDOW *skb;
    int k = 0, event = 0;

    check_valid_map(sbk1);
    initscr();
    mvprintw(0,0,sbk1->map);
    keypad(stdscr, TRUE);
    while (sbk1->event != 1) {
        k = getch();
        move_map(sbk1, k);
        mvprintw(0,0,sbk1->map);
        check_win(sbk1);
        check_lose(sbk1);
        refresh();
    }
    endwin();
    return 1;
}

int main(int arc, char **arv)
{
    char *buffer;
    struct stat sfile;
    sbk *sbk1 = NULL;
    int result = 0;
    if (arc == 2)
        flag_h(arc, arv);
    sbk1 = malloc(sizeof(sbk));
    stat (arv[1], &sfile);
    buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    sbk1->map = open_skb(arv, buffer);
    char *map2 = malloc(sizeof(char) * (sfile.st_size + 1));
    my_strcpy(map2, sbk1->map);
    sbk1->map2 = map2;
    sbk1->arv1 = arv;
    sbk1->buffer = buffer;
    test_error(arc, sbk1);
    result = main_sokoban(arv, sbk1);
    free_all(buffer, sbk1, map2);
    return result;
}
