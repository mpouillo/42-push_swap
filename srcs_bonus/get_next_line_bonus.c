/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:38:02 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/24 08:06:05 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/get_next_line_bonus.h"

static int	find_nl(char const *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line_update_stash(char **stash, char *line, char *src)
{
	int		nl;
	char	*temp_stash;

	nl = find_nl(src);
	line = ft_strljoin(line, src, nl + 1);
	if (!line)
		return (put_error(stash, &line));
	if (src[nl + 1] != '\0')
	{
		temp_stash = ft_strldup(&src[nl + 1], ft_strlen_gnl(src) - nl - 1);
		if (!temp_stash)
			return (put_error(&line, stash));
	}
	else
		temp_stash = NULL;
	if (*stash && *stash == src)
		free(*stash);
	*stash = temp_stash;
	return (line);
}

static char	*read_and_fill(int fd, char *line, char **stash)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	ssize_t		bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (find_nl(buf) != -1)
			return (extract_line_update_stash(stash, line, buf));
		line = ft_strljoin(line, buf, (int)bytes_read);
		if (!line)
			return (put_error(stash, &line));
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (put_error(&line, stash));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (stash)
	{
		if (find_nl(stash) != -1)
			return (extract_line_update_stash(&stash, line, stash));
		line = ft_strljoin(line, stash, ft_strlen_gnl(stash));
		free(stash);
		stash = NULL;
		if (!line)
			return (NULL);
	}
	return (read_and_fill(fd, line, &stash));
}
