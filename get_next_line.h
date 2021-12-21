
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>


void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putchar_fd(char s, int fd);
char    *get_next_line(int  fd);


#endif
