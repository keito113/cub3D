/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2026/02/10 15:14:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strjoin_and_free(char *stash, char *buf)
{
	char	*joined;

	if (!stash)
		return (gnl_ft_strdup(buf));
	joined = gnl_ft_strjoin(stash, buf);
	free(stash);
	return (joined);
}

char	*extract_line(char *stash)
{
	char	*line;
	char	*newline_ptr;
	size_t	line_len;
	size_t	i;

	i = 0;
	newline_ptr = gnl_ft_strchr(stash, '\n');
	if (newline_ptr == NULL)
		line_len = ft_strlen(stash);
	else
		line_len = (size_t)(newline_ptr - stash + 1);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	char	*newline_ptr;
	char	*new_stash;
	size_t	len;

	if (!stash)
		return (NULL);
	newline_ptr = gnl_ft_strchr(stash, '\n');
	if (!newline_ptr)
		return (free(stash), NULL);
	newline_ptr++;
	if (*newline_ptr == '\0')
		return (free(stash), NULL);
	len = ft_strlen(newline_ptr);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	gnl_ft_memcpy(new_stash, newline_ptr, len);
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash)
		stash = gnl_ft_strdup("");
	if (!stash)
		return (free(buf), NULL);
	while (stash && !gnl_ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		stash = strjoin_and_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
		return (NULL);
	stash = update_stash(stash);
	return (line);
}
