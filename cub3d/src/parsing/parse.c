/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:26:53 by javperez          #+#    #+#             */
/*   Updated: 2024/08/13 19:23:52 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error_map(t_map *map)
{
	if (!ft_wall_error(map))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	return (1);
}

void	parse_error(t_map *map, char *message)
{
	ft_printf(message);
	if (map->map_tab)
		free_double_array(map->map_tab);
	if (map->line)
		free(map->line);
	if (map->map_line)
		free(map->map_line);
	free_rgb_texture(map);
	exit (EXIT_FAILURE);
}

/*
    FIX_SIZE_MAP

    It use set_size_data() to set the heigh and width of the map.
    If they're not defined, it means that more or less than one
    player is placed on the map.
    
    Based on the width, this function resize each line to have
    the same width than the longer line and form a rectangle,
    to make the vertical parsing easier.
*/

void	fix_size_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	set_size_data(map, map->map_tab, i, j);
	if (map->height_map == 0 && map->width_map == 0) //Como hacemos return en la funcion de antes estos valores son 0
		parse_error(map, "Error\nOnly one player is required on the map\n");

	while (map->map_tab[i])
	{
		if (ft_strlen_cub3d(map->map_tab[i]) <= map->width_map)
		{
			map->map_tab[i] = ft_resize_line(map->map_tab[i], map->width_map);
			if (!map->map_tab[i])
				parse_error(map, "Error\nMalloc error\n");
		}
		i++;
	}
}

/*
        FT_READ_MAP
    
    read each line in fd, and join them in map_line. 
    At the end, map_line is split with the '/' separator added
    by ft_strjoin_cub3d, and stocked in map_tab.
    if a line is empty, a space is added to count the line in
    ft_split.
    if a '/' is added before the parsing, ft_parse_error is called
    to free and exit the program properly.
*/

void	ft_read_map(int fd, t_map *map)
{
	while (1)
	{
		map->line = get_next_line(fd);
		if (!map->line) //cuando no hay lineas termina
			break ;
		if (map->line[0] == '\n')
			map->line[0] = ' ';
		if (get_map_stat(map, map->line) == 1)
		{
			//hemo movido la línea al inicio del mapa porque hemos parseado en get_map_stat las lineas de los paths
			if (ft_strchr(map->line, '/')) 
				parse_error(map, "Error\nInvalid character in map\n");
			map->map_line = ft_strjoin_cub3d(map->map_line, map->line); //Vamos a añadir una / al final de cada linea del mapa para después dividirlo con split
			//map_line es una string giganete con todo el mapa divido en /
		}
		free(map->line);
	}
	//dividimos la string gigante en un array con cada linea del mapa
	map->map_tab = ft_split(map->map_line, '/');
	free(map->map_line);
	map->map_line = NULL;

	fix_size_map(map); //igualar todas las lineas al mismo tamaño para facilitar el parseo vertical
}

int	ft_parse_map(t_map *map, int fd)
{
	ft_read_map(fd, map); //Aqui leiamos el mapa y lo almacenabamos en una array
	if (!error_map(map)) //Aqui verificamos que el mapa este cerrado
		return (0);
	close(fd);
	return (1);
}
