#include "get_next_line.h"


char    *get_next_line(int  fd)
{
    char        buf[BUFFER_SIZE + 1];
    static char *final;
    int         ret_val;

    ret_val = 1;
    while (ret_val != 0 && (ft_strchr(final, '\n') == 0))
    {
        ret_val = read(fd, buf, BUFFER_SIZE);
        printf("****retvalue = %d ****** || **** copy = %s ****\n", ret_val, buf);
        buf[ret_val] = '\0';
        final = ft_strjoin(final, buf);
    }
    return (final);
}               

int main()
{
    int fd;
    //char *yo;

    fd = open("55", O_RDONLY | O_CREAT);
    //printf("fd %d", fd);
    for (size_t i = 0; i < 5 ; i++)
    {
        printf("%s", get_next_line(fd));
    }
    
    /*for(int i = 0; i < 100; i++)
    {
        yo = get_next_line(fd);
        if (!yo)
            break;
        free(yo);
    }
    close(fd);
    */
}