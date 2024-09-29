/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:26:20 by javperez          #+#    #+#             */
/*   Updated: 2024/08/13 19:48:48 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			if (map->map_tab[i][j] == '1')
				draw_case(map, j * 7, i * 7, 0x000000); //Dibuja el 1 en un cuadrado de 7 x 7 pixeles
			else if (map->map_tab[i][j] == '0')
				draw_case(map, j * 7, i * 7, create_trgb(0, map->rgb_sky[0], //Dibuja el 0 en un cuadrado de 7 x 7 pixeles
						map->rgb_sky[1], map->rgb_sky[2]));
			else if (is_valid_char(map->map_tab[i][j], "NSEW"))
				draw_case(map, j * 7, i * 7, 0xEEEE20); //Dibuja el NSEW en un cuadrado de 7 x 7 pixeles
			else
				draw_case(map, j * 7, i * 7, 0x353535); //Dibuja el ESPACIO en un cuadrado de 7 x 7 pixeles
			j++;
		}
		i++;
	}
}

void	actualise_minimap(t_map *map, int old_x, int old_y) //Cada vez que te mueves
{
	draw_case(map, (int)map->pos_x * 7, (int)map->pos_y * 7, 0xEEEE20);
	if ((int)map->pos_x != old_x)
		draw_case(map, old_x * 7, old_y * 7,
			create_trgb(0, map->rgb_sky[0], map->rgb_sky[1], map->rgb_sky[2]));
	if ((int)map->pos_y != old_y)
		draw_case(map, old_x * 7, old_y * 7,
			create_trgb(0, map->rgb_sky[0], map->rgb_sky[1], map->rgb_sky[2]));
}

void	minimap_pix_put(t_map *map, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > map->display_height - 1 || x < 0
		|| x > map->display_width - 1)
		return ;
	pixel = (map->minimap.addr + (y * map->minimap.line_len
				+ x * (map->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	draw_case(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			minimap_pix_put(map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
