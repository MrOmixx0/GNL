/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:50:21 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/02 16:43:06 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*full_reading(char **reminder)
{
	char	*line;

	line = ft_strdup(*reminder);
	free(*reminder);
	*reminder = NULL;
	return (line);
}

char	*read_line(char **reminder)
{
	char	*line;
	char	*newline;
	char	*temp;
	size_t	len;

	if (!*reminder || !**reminder)
		return (NULL);
	newline = ft_strchr(*reminder, '\n');
	if (!newline)
		return (full_reading(reminder));
	len = newline - *reminder + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *reminder, len + 1);
	temp = ft_strdup(newline + 1);
	free(*reminder);
	*reminder = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		reminder = ft_strjoin(reminder, buffer);
		if (ft_strchr(reminder, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	return (read_line(&reminder));
}
