/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pafuente <pafuente@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:20:03 by pafuente          #+#    #+#             */
/*   Updated: 2025/05/13 14:05:08 by pafuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//reads data from a file descriptor fd and appends it to a given string
//str until a newline character is encountered or the end of the file is reached

char	*ft_readfile(int fd, char *str)
{
	char	*buffer;
	char	*temp;
	ssize_t	len;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while ((!str || !ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(str);
			str = NULL;
			return (NULL);
		}
		buffer[len] = '\0';
		temp = ft_strjoin(str, buffer);
		str = temp;
	}
	free(buffer);
	return (str);
}

// extracts a new string from the given string str up to and including 
//the first newline character (\n)

char	*ft_newline(char *str)
{
	char	*new;
	size_t	i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

//return a new string that contains the part of the original string
// after the first newline character (\n).

char	*ft_restline(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

// The get_next_line function is designed to read a line
//from a file descriptor fd and return it as a string.
char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_readfile(fd, str);
	if (!str || str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	out = ft_newline(str);
	str = ft_restline(str);
	return (out);
}
