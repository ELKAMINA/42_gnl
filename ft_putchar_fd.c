
#include "get_next_line.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
