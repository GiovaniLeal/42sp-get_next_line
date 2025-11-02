/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:03:04 by giodos-s          #+#    #+#             */
/*   Updated: 2025/09/15 22:03:04 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                        FT_EXTRACT_LINE                                     */
/* ************************************************************************** */
char	*ft_extract_line(char *raw)
{
	int		i;
	char	*line;

	i = 0;
	if (!raw || !raw[0])
		return (NULL);
	while (raw[i] && raw[i] != '\n')
		i++;
	if (raw[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (raw[i] && raw[i] != '\n')
	{
		line[i] = raw[i];
		i++;
	}
	if (raw[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* ************************************************************************** */
/*                        FT_LINE_TRIM                                        */
/*                                                                            */
/*   - Removes the first line from 'raw' (up to and including '\n').         */
/*   - Returns a newly allocated string containing the remainder.            */
/*   - Frees 'raw'. Returns NULL if there is no more content.                */
/* ************************************************************************** */
char	*ft_line_trim(char *raw)
{
	int		i;
	int		j;
	char	*trim;

	if (!raw)
		return (NULL);
	i = 0;
	j = 0;
	while (raw[i] && raw[i] != '\n')
		i++;
	if (raw[i] == '\n')
		i++;
	if (!raw[i])
		return (free(raw), NULL);
	trim = malloc(ft_strlen(raw + i) + 1);
	if (!trim)
		return (free(raw), NULL);
	while (raw[i])
		trim[j++] = raw[i++];
	trim[j] = '\0';
	free(raw);
	return (trim);
}

static char	*ft_read_once(int fd, char *raw, int *eof)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (free(buffer), free(raw), NULL);
	if (bytes == 0)
	{
		free(buffer);
		*eof = 1;
		return (raw);
	}
	buffer[bytes] = '\0';
	if (!raw)
		raw = ft_strjoin("", buffer);
	else
		raw = ft_join_and_free(raw, buffer);
	free(buffer);
	return (raw);
}

char	*ft_read_file(int fd, char *raw_text)
{
	int	eof;

	eof = 0;
	while (!raw_text || (!ft_strchr(raw_text, '\n') && !eof))
	{
		raw_text = ft_read_once(fd, raw_text, &eof);
		if (!raw_text)
			return (NULL);
	}
	if (!raw_text || !*raw_text)
		return (free(raw_text), NULL);
	return (raw_text);
}

/* ************************************************************************** */
/*                        GET_NEXT_LINE                                       */
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static char	*raw_text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_text = ft_read_file(fd, raw_text);
	if (!raw_text)
		return (NULL);
	line = ft_extract_line(raw_text);
	raw_text = ft_line_trim(raw_text);
	return (line);
}

// /* *********************************************************************** */
// /*                          GNL MAIN TEST                                  */
// /*                                                                         */
// /*                  LIBRARIES : [PRINTF] - [OPEN]                          */
// /*  compile :   cc -Wall -Wextra -Werror -D BUFFER_SIZE=42                 */
// /*	   	get_next_line.c get_next_line_utils.c -o gnl              */
// /*                                                                         */
// /* *********************************************************************** */
// #include <stdio.h> 
// #include <fcntl.h>
//
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		count = 1;
//
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("Line %d: %s", count++, line);
// 		free(line);
// 	}
// 	if (close(fd) == -1)
//	{
//		perror(close);
//		return(1);
//	}
// 	return (0);
// }