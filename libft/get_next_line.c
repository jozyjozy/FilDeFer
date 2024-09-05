/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:34:27 by jlarue            #+#    #+#             */
/*   Updated: 2023/01/06 13:32:40 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*readline(int fd, char *buf, char *stash)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!stash)
			stash = ft_strdup("");
		char_temp = stash;
		stash = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (stash);
}

int	end_of_line(char *line)
{
	size_t	result;

	result = 0;
	while (line[result] != '\n' && line[result] != '\0')
		result++;
	return (result);
}

static char	*trim_stash_extracting_current_line(char *line)
{
	size_t	eol_index;
	size_t	line_size;
	char	*stash_next;

	eol_index = end_of_line(line);
	line_size = ft_strlen(line);
	if (line[eol_index] == '\0' || line[1] == '\0')
		return (0);
	stash_next = ft_substr(line, eol_index + 1, line_size - eol_index);
	line[eol_index + 1] = '\0';
	return (stash_next);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = readline(fd, buf, stash);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = trim_stash_extracting_current_line(line);
	return (line);
}
