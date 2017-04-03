
all:
	gcc -Wall -Wextra -Werror -o get_next_line.o -c get_next_line.c
	gcc -Wall -Wextra -Werror -o main.o -c -c main.c
	gcc -o test_gnl main.o get_next_line.o  -L . -lft
	@make clean

clean: 
		/bin/rm -f get_next_line.o main.o

fclean: clean
		/bin/rm -f test_gnl

re: fclean all
