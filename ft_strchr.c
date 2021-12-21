
#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (sent[i] == character)
			return (1);
		i ++;
	}
	return (0);
}
