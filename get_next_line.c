/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminaelk <aminaelk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:22:11 by ael-khat          #+#    #+#             */
/*   Updated: 2021/12/25 13:08:25 by aminaelk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_get_nls(int fd, char *read_sentence)
{
	char	*buf;
	int		ret_val;

	ret_val = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ret_val != 0 && (ft_strchr(read_sentence, '\n') == 0))
	{
		ret_val = read(fd, buf, BUFFER_SIZE);
		if (ret_val == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret_val] = '\0';
		read_sentence = ft_strjoin(read_sentence, buf);
	}
	free(buf);
	return (read_sentence);
}

int	get_index_nl(char	*result)
{
	int		i;

	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	return (i);
}

char	*get_string_nl(char		*result, int	next_index)
{
	char	*tmp;
	int		j;

	j = 0;
	if (result[next_index] == '\n')
		tmp = malloc(sizeof(char) * next_index + 2);
	else
		tmp = malloc(sizeof(char) * (next_index + 1));
	while (result[j] && j < next_index)
	{
		tmp[j] = result[j];
		j++;
	}
	if (result[next_index] == '\n')
	{
		tmp[j] = '\n';
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*next_sent(int i, char *final)
{
	char	*memory;
	int		size_rest;
	int		j;

	j = 0;
	size_rest = ft_strlen(final) - i;
	if	(!final[i])
	{
		free(final);
		return (NULL);
	}
	memory = malloc(sizeof(char) * size_rest + 1);
	i++;
	while (j < size_rest)
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
	char		*fst_nls;
	int			next_index;
	static char	*next_sentence;
	char		*string_to_display;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fst_nls = read_get_nls(fd, next_sentence);
	if	(!fst_nls)
		return (NULL);
	if (!fst_nls[0])
	{
		free(fst_nls);
		fst_nls = NULL;
		return (NULL);
	}
	next_index = get_index_nl(fst_nls);
	string_to_display = get_string_nl(fst_nls, next_index);
	next_sentence = next_sent(next_index, fst_nls);
	return (string_to_display);
}