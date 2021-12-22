#include "get_next_line.h"


char    *read_get_nls(int  fd, char *next_sentence)
{
    char        buf[BUFFER_SIZE + 1];
    int         ret_val;

    ret_val = 1;
    while (ret_val != 0 && (ft_strchr(next_sentence, '\n') == 0))
    {
        ret_val = read(fd, buf, BUFFER_SIZE);
        buf[ret_val] = '\0';
        next_sentence = ft_strjoin(next_sentence, buf);
    }
    printf("******return value %d\n********", ret_val);
    return (next_sentence);
}


int   get_nl_display(char   *result)
{
       static int   i;
       //char         *tmp;
       int          j;

       i = ft_strchr(result, '\n');
       /*if   (i == 0)
       {
           tmp = malloc(sizeof(char) * f)
       }
        */
       j = 0;
       while (j <= i)
       {
           write (1, &result[j], 1);
           j ++;
       }
       i ++;
       //printf(" index pour le premier backslash %d", i);
       return (i);
}

char    *next_sent(int  i, char *final)
{
    static char    *memory;

    memory = ft_strcpy(memory, final, i);
    return (memory);
}


char    *get_next_line(int fd)
{
    char    *fst_nls; // ma chaine qui va contenir les NL
    static int     next_index; // stocke l'index de fin de phrase avant le premier \n
    static char    *next_sentence;

    fst_nls = read_get_nls(fd, next_sentence);
    // read-get-nl me renvoie les premieres phrases contenant \n : Hello>Zine>\ncava>\ntu>\0 ou > est un espace;
    next_index = get_nl_display(fst_nls); // j'envoie mon fst nl a get-nl-display pour quelle maffiche les phrases et pour quelle me renvoie l'index juste apres le premier \n
    next_sentence = next_sent(next_index, fst_nls);
    return (NULL);
}

int main()
{
    int fd;
    //char *yo;

    fd = open("55", O_RDONLY | O_CREAT);
    //printf("fd %d", fd);
    for (size_t i = 0; i < 2 ; i++)
    {
        printf("******************* %s ******************\n", get_next_line(fd));
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