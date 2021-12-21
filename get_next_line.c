#include "get_next_line.h"


char    *get_next_line(int  fd)
{
    char        buf[BUFFER_SIZE + 1];
    static char *statical;
    int         i = 0;
    int         ret_val; 

    ret_val = 1;
    while (ret_val != 0 && (ft_strchr(statical, '\n') == 0))
    {
        ret_val = read(fd, buf, BUFFER_SIZE);
        printf("retvalue %d", ret_val);
        buf[ret_val] = '\0';
        statical = ft_strjoin(statical, buf);
    }
    printf("sttical = %s", statical);
    return ("HELLO");
}               

int main()
{
    int fd;
    //char *yo;

    fd = open("42", O_RDONLY);
    printf("fd %d", fd);
    get_next_line(fd);
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