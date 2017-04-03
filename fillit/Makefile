
CC = gcc

FLAGS = -Wall -Werror -Wextra 

NAME = fillit

SOURCES = beq.c get_map.c nr_retur_line.c  \
check_pcs.c main.c place.c att_pcs.c error.c min_square.c \
check_buf.c finish.c rem.c


OBJECTS = $(SOURCES:.c=.o)

HEADER = swag.h

$(NAME):
		@$(CC) $(FLAGS) -c $(SOURCES)
		@$(CC) $(FLAGS) $(SOURCES) -o $(NAME)
		@make clean

all: $(NAME)

clean:
		@rm -rf $(OBJECTS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
