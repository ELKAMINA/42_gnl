#include "get_next_line.h"

char	*ft_strcpy(char	*dest, char	*src, int	i)
{
	int	j;

	j = 0;
	//printf("taille src = %ld || i  = % d", ft_strlen(src), i);
	dest = malloc(sizeof(char) * (ft_strlen(src) - i) + 1);
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
