/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:25:59 by javperez          #+#    #+#             */
/*   Updated: 2024/08/13 19:30:25 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_test_extension(char *argv)
{
	int	i;
	int	j;

	i = ft_strlen(argv);
	j = 0;
	i -= 4;
	//maps.cub
	while (argv[i] != '\0')
	{
		if (j == 0 && argv[i] != '.')
			return (0);
		if (j == 1 && argv[i] != 'c')
			return (0);
		if (j == 2 && argv[i] != 'u')
			return (0);
		if (j == 3 && argv[i] != 'b')
			return (0);
		i++;
		j++;
	}
	return (1);
}

//Checkea la extension y si tiene contenido

int	check_valid_file(char *argv)
{
	int		fd;
	int		result;
	char	test[1];

	if (!ft_test_extension(argv))
	{
		ft_printf("Error\nBad extension\n");
		return (0);
	}
	fd = open(argv, O_RDONLY);
	result = read(fd, test, 1);
	if (result <= 0)
	{
		if (result == 0)
			ft_printf("Error\nEmpty file\n");
		else if (result < 0)
			ft_printf("Error\nInvalid entry\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	init_struct(t_map *map)
{
	int	i;

	i = 0;
	map->map_tab = NULL;
	map->width_map = 0;
	map->height_map = 0;
	map->rgb_floor[0] = -1; //Ya que son colores, no podemos inicializarlo en 0 0 0 porque eso sería el negro
	map->rgb_floor[1] = -1;
	map->rgb_floor[2] = -1;
	map->rgb_sky[0] = -1;
	map->rgb_sky[1] = -1;
	map->rgb_sky[2] = -1;
	map->line = NULL;
	map->map_line = NULL;
	while (i < 5)
	{
		map->img[i].mlx_img = NULL;
		map->img[i].path = NULL;
		i++;
	}
	map->minimap.mlx_img = NULL;
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	init_struct(&map); //Inicializamos valores ¿por qué no los demás? 
	if (argc != 2)

		parse_error(&map, "Error\nOne argument required\n"); //Liberamos memoria e imprimimos mensaje de error
	if (!check_valid_file(argv[1]))
		return (1);

	fd = open(argv[1], O_RDONLY);

	if (fd <= 0)
	{
		ft_printf("Error\nFailed to open file\n");
		return (37);
	}

	if (!ft_parse_map(&map, fd))
	{
		free_double_array(map.map_tab);
		return (38);
	}

	ft_init_game(&map);
	return (0);
}
