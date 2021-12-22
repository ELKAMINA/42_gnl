
#include "get_next_line.h"

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
