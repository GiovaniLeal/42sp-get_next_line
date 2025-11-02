/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:48:46 by giodos-s          #+#    #+#             */
/*   Updated: 2025/09/15 21:48:46 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ************************************************************************** */
/*                               CONFIGURATION                                */
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ************************************************************************** */
/*                      LIBRARIES = [READ] - [MALLOC]                         */
/* ************************************************************************** */
# include <unistd.h>
# include <stdlib.h>

/* ************************************************************************** */
/*                               FUNCTIONS                                    */
/* ************************************************************************** */
char	*get_next_line(int fd);
char	*ft_line_trim(char *raw_txt);
char	*ft_extract_line(char *raw_txt);
char	*ft_read_line(int fd, char *raw);
char	*ft_join_and_free(char *raw_text, char *temp_buffer);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);

#endif