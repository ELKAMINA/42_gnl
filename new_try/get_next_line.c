#include "get_next_line.h"

char	*get_nl(int	fd, char	*file)
{
	int		ret_value;
	char	*temp;

	ret_value = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (ret_value !=0 && (!ft_strchr(file, '\n')))
	{
		ret_value = read(fd, temp, BUFFER_SIZE);
		if (ret_value == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[ret_value] = '\0';
		file = ft_strjoin(file, temp);
	}
	free(temp);
	return (file);
}

char	*dis_bf_nl(char	*file)
{
	size_t		i;
	size_t		j;
	char		*new_line;

	i = 0;
	j = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		new_line = malloc(sizeof(char) * i + 2);
	else
		new_line = malloc(sizeof(char) * i + 1);
	if (!new_line)
		return (NULL);
	while (file[j] && file[j] != '\n')
	{
		new_line[j] = file[j];
		j ++;
	}
	if (file[j] == '\n')
	{
		new_line[j] = '\n';
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*stock(char	*file)
{
	size_t		i;
	size_t		j;
	char	*stock;

	i = 0;
	j = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	stock = malloc(sizeof(char) * ft_strlen(file) - i + 1);
	i ++;
	while (j < ft_strlen(file) - i)
	{
		stock[j] = file[i + j];
		j ++;
	}
	stock[j] = '\0';
	free(file);
	return (stock);
}

char    *get_next_line(int	fd)
{
	static char	*file;
	char		*to_display;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	file = get_nl(fd, file);
	if (!file)
		return (NULL);
	if (!file[0])
	{
		free(file);
		file  = NULL;
		return (NULL);
	}
	to_display = dis_bf_nl(file);
	file = stock(file);
	return (to_display);
}

/*int	main()
{
	int	fd;

	fd = open("44", O_RDONLY);
	for (int i = 0; i < 5; i++) {
		printf("%s", get_next_line(fd));
	}
}
*/
