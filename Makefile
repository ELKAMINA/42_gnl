
CC : gcc -Wall -Werror -Wextra

NAME : libftprintf.a

SRC  : get_next_line.c 

OBJ  : $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean re
