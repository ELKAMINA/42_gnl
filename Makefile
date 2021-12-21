
CC : gcc -Wall -Werror -Wextra BUFFER_SIZE=5

SRC  : get_next_line.c ft_strchr.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strdup.c ft_strjoin.c\ ft_strlen.c\

OBJ  : $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean re
