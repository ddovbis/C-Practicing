NAME = 2048

SRC = main.c map.c moves.c ops.c utils.c game.c ft_atoi.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I . -c $(SRC)
	gcc $(FLAGS) $(OBJ) -lncurses -o $(NAME)
	make clean

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all
