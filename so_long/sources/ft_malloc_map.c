/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:18:21 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 19:02:44 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_bad_malloc(void)
{
	write(2, "Error\nMap not malloc\n", 21);
	exit (1);
}

void	ft_map_size(t_game *game)
{
	char	*line;
	int		fd;

	fd = open(game->map_file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nMap not read\n", 19);
		exit (1);
	}
	game->width = ft_strlen(line) - 1;
	game->height = 0;
	while (line)
	{
		if (ft_strlen(line) - 1 != game->width)
		{
			write(2, "Error\nMap not valid\n", 20);
			exit (1);
		}
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_map(t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(game->map_file_path, O_RDONLY);
	i = 0;
	game->map = malloc(sizeof (char *) * (game->height + 1));
	if (!game->map)
		ft_bad_malloc();
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_bad_malloc();
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			ft_bad_malloc();
		game->map[i][game->width] = '\0';
		i++;
		free(line);
	}
	line = NULL;
	game->map[i] = NULL;
	close(fd);
}
