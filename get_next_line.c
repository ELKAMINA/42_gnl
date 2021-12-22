/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:22:11 by ael-khat          #+#    #+#             */
/*   Updated: 2021/12/22 17:34:39 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_get_nls(int fd, char *next_sentence)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret_val;

	ret_val = 1;
	while (ret_val != 0 && (ft_strchr(next_sentence, '\n') == 0))
	{
		ret_val = read(fd, buf, BUFFER_SIZE);
		buf[ret_val] = '\0';
		next_sentence = ft_strjoin(next_sentence, buf);
	}
	return (next_sentence);
}

int	get_index_nl(char	*result)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		tmp = malloc(sizeof(char) * i + 1);
	else
		tmp = malloc(sizeof(char) * i);
	while (result[j] && result[j] != '\n')
	{
		tmp[j] = result[j];
		j++;
	}
	if (result[j] == '\n')
	{
		tmp[j] = '\n';
		j++;
	}
	tmp[j] = '\n';
	i = i + 1;
	return (i);
}

char	*get_string_nl(char		*result)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		tmp = malloc(sizeof(char) * i + 1);
	else
		tmp = malloc(sizeof(char) * i);
	while (result[j] && result[j] != '\n')
	{
		tmp[j] = result[j];
		j++;
	}
	if (result[j] == '\n')
	{
		tmp[j] = '\n';
		j++;
	}
	return (tmp);
}

char	*next_sent(int i, char *final)
{
	char	*memory;

	memory = malloc(sizeof(char) * (ft_strlen(final) - i + 1));
	memory = ft_strcpy(memory, final, i);
	return (memory);
}

char	*get_next_line(int fd)
{
	char		*fst_nls;
	int			next_index;
	static char	*next_sentence;
	char		*string_to_display;

	if (fd <= 0)
		return (NULL);
	fst_nls = read_get_nls(fd, next_sentence);
	next_index = get_index_nl(fst_nls);
	string_to_display = get_string_nl(fst_nls);
	next_sentence = next_sent(next_index, fst_nls);
	return (string_to_display);
}
