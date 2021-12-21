#include "get_next_line.h"

char    *get_next_line(int  fd)
{
    char        tmp[BUFFER_SIZE + 1];
    //static char *final_buff;
    int         ret_val;

    if  (fd == -1)
        ft_putstr_fd("Open file Error", 1);
    printf("fd %d", fd);
    printf("BUFF SIZE %d", BUFFER_SIZE);
    ret_val = read(fd, tmp, BUFFER_SIZE);
    printf("ret_value %d", ret_val);
    /*while (ret_val >= 0)
    {
        ret_val = read (fd, tmp, BUFFER_SIZE);
        tmp[ret_val] = '\0';
        ft_putstr_fd(tmp, 1);
    }
    
    */
    return ("HELLO");
}

int main()
{
    int fd;

    fd = open("42", O_RDWR | O_CREAT, S_IRWXU);
    if  (fd == -1)
        ft_putstr_fd("Open file Error", 1);
    //printf("fd dans le main %d", fd);
    ft_putstr_fd("Hey you", fd);
    get_next_line(fd);
}