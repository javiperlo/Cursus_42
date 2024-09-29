/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:54:01 by javperez          #+#    #+#             */
/*   Updated: 2023/11/16 15:57:52 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_new_line(str);
	str = new_line(str);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("txt_files/file1", O_RDONLY); //Abrimos el diccionario
	i = 1;
	while (i < 5) //Aquí ponemos las lienas que queramos leer
	{
		line = get_next_line(fd1); //Almacenamos en "line", la 
		//variable almacenada de get_next_line(fd);
		printf("line [%02d]: %s", i, line); // Y la printeamos
		free(line); //Liberamos la memoria de "line", 
		//para poder almacenar otra cadena distinta.
		i++;
	}
	close(fd1); //Una vez hayamos terminado de leer las
	//lineas que queramos, cerramos el diccionario
	return (0);
}*/