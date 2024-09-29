/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:24:30 by javperez          #+#    #+#             */
/*   Updated: 2023/11/16 15:57:35 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_new_line(char *str)
{
	int		i;
	char	*cut_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	cut_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!cut_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cut_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cut_str[i] = str[i];
		i++;
	}
	cut_str[i] = '\0';
	return (cut_str);
}

char	*new_line(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*read_line(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_new_line(str[fd]);
	str[fd] = new_line(str[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		fd_two;
	char	*line;
	int		i;

	fd = open("../txt_files/file1", O_RDONLY);
	fd_two = open("../txt_files/file2", O_RDONLY);
	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		else
			printf("%s", "NULL");
		free(line);
		line = get_next_line(fd_two);
		if (line)
			printf("%s", line);
		else
			printf("%s", line);
		free(line);
		i ++;
	}
	close(fd);
}*/
