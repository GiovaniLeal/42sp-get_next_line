/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giodos-s <giodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:02:55 by giodos-s          #+#    #+#             */
/*   Updated: 2025/09/15 22:02:55 by giodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*                               FT_STRLEN                                    */
/*                                                                            */
/*   - Returns the length of a string 's'.                                    */
/*   - Returns 0 if 's' is NULL.                                              */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                               FT_STRCHR                                    */
/*                                                                            */
/*   - Returns a pointer to the first occurrence of character 'c' in 's'.     */
/*   - Returns NULL if 's' is NULL or 'c' is not found.                       */
/*   - Supports searching for the null-terminator '\0'.                       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	if (!s)
		return (NULL);
	i = 0;
	cast_s = (char *)s;
	while (cast_s[i])
	{
		if (cast_s[i] == (char)c)
			return (&cast_s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&cast_s[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                             FT_STRJOIN                                     */
/*                                                                            */
/*   - Joins two strings into a new allocated string.                         */
/*   - Handles NULL inputs: treats NULL as empty string.                      */
/*   - Returns the newly allocated string, or NULL if allocation fails.       */
/* ************************************************************************** */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	return (new_str);
}

/* ************************************************************************** */
/*                        FT_JOIN_AND_FREE                                    */
/*                                                                            */
/*   - Joins 'raw_text' and 'temp_buffer' into a new string.                  */
/*   - Frees the original 'raw_text' to prevent memory leaks.                 */
/*   - Returns the newly allocated joined string, or NULL if allocation fails.*/
/* ************************************************************************** */
char	*ft_join_and_free(char *raw_text, char *temp_buffer)
{
	char	*joined;

	joined = ft_strjoin(raw_text, temp_buffer);
	free(raw_text);
	return (joined);
}

/* ************************************************************************** */
/*                              FT_MEMCPY                                     */
/*                                                                            */
/*   - Copies 'n' bytes from memory area 'src' to memory area 'dst'.          */
/*   - The memory areas must not overlap.                                     */
/*   - Returns a pointer to 'dst'.                                            */
/*   - If both 'dst' and 'src' are NULL, returns NULL.                        */
/* ************************************************************************** */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_bytes;
	const unsigned char	*src_bytes;

	if (!dest && !src && n > 0)
		return (NULL);
	dest_bytes = (unsigned char *)dest;
	src_bytes = (unsigned char *)src;
	while (n--)
	{
		*dest_bytes = *src_bytes;
		src_bytes++;
		dest_bytes++;
	}
	return (dest);
}
