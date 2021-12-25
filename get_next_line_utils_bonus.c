
#include "get_next_line_bonus.h"

int	ft_strchr(char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 0;
	if (!s)
		return (0);
	while (i <= ft_strlen(sent))
	{
		if (sent[i] == character)
			return (i);
		i ++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char	*s2)
{
	char	*conc;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1))
		s1 = ft_strdup("");
	conc = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (conc == NULL)
		return (NULL);
	while (s1[j])
	{
		conc[j] = s1[j];
		j ++;
	}
	while (s2[i])
	{
		conc[j] = s2[i];
		j++;
		i++;
	}
	conc[j] = '\0';
	free(s1);
	return (conc);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
