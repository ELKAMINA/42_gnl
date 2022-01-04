/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:11:50 by ael-khat          #+#    #+#             */
/*   Updated: 2022/01/04 15:12:55 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_get_nls(int fd, char *tmp)
{
	char	*buf;
	int		v_ret;

	v_ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (v_ret != 0 && !ft_strchr(tmp, '\n'))
	{
		v_ret = read(fd, buf, BUFFER_SIZE);
		if (v_ret == -1)
		{
			free(buf);
			return (NULL);
		}				
		buf[v_ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_string_nl(char		*result)
{
	char			*tmp;
	unsigned long	j;
	unsigned long	i;

	j = 0;
	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		tmp = malloc(sizeof(char) * i + 2);
	else
		tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (result[j] && j < i)
	{
		tmp[j] = result[j];
		j++;
	}
	if (result[j] == '\n')
		tmp[j++] = '\n';
	tmp[j] = '\0';
	return (tmp);
}

char	*next_sent(char *final)
{
	char				*memory;
	unsigned long		j;
	unsigned long		i;

	i = 0;
	while (final[i] && final[i] != '\n')
		i++;
	if (!final[i])
	{
		free(final);
		return (NULL);
	}
	memory = malloc(sizeof(char) * (ft_strlen(final) - i) + 1);
	if (!memory)
		return (NULL);
	i++;
	j = 0;
	while (final[i + j])
	{
		memory[j] = final[i + j];
		j++;
	}
	memory[j] = '\0';
	free(final);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*next_sentence[1024];
	char		*string_to_display;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	next_sentence[fd] = read_get_nls(fd, next_sentence[fd]);
	if (!next_sentence[fd])
		return (NULL);
	if (!next_sentence[fd][0])
	{
		free(next_sentence[fd]);
		next_sentence[fd] = NULL;
		return (NULL);
	}
	string_to_display = get_string_nl(next_sentence[fd]);
	next_sentence[fd] = next_sent(next_sentence[fd]);
	return (string_to_display);
}
