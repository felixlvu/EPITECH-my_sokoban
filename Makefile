##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = ./src/main.c \
	  ./src/move_map.c \
	  ./src/check_map.c \
	  ./src/check_lose.c \
	  ./src/my_strlen_sbk.c \
	  ./src/move_up_down.c \
	  ./src/free_all.c \

OBJ = $(SRC:.c=.o)

LIB = -L ./lib/my/ -lmy

CFLAGS = -I ./include/

NAME = my_sokoban

$(NAME): $(OBJ)
	make -C ./lib/my/
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LIB) -lncurses

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all

debug:	CFLAGS += -g3
debug:	re
