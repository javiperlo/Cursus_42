/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:27:29 by javperez          #+#    #+#             */
/*   Updated: 2024/05/26 19:27:30 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_map *map, double next_x, double next_y, char sign)
{
	int	old_x;
	int	old_y;

	old_x = (int)map->pos_x;
	old_y = (int)map->pos_y;
	if (sign == '+')
	{
		if (map->map_tab[(int)map->pos_y][(int)(map->pos_x + next_x)] != '1')
			map->pos_x += next_x;
		if (map->map_tab[(int)(map->pos_y + next_y)][(int)map->pos_x] != '1')
			map->pos_y += next_y;
	}
	else if (sign == '-')
	{
		if (map->map_tab[(int)map->pos_y][(int)(map->pos_x - next_x)] != '1')
			map->pos_x -= next_x;
		if (map->map_tab[(int)(map->pos_y - next_y)][(int)map->pos_x] != '1')
			map->pos_y -= next_y;
	}
	if (old_x != map->map_x || old_y != map->map_y)
		actualise_minimap(map, old_x, old_y);
}

void	rotate(t_map *map, double rot_spd)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = map->dir_x;
	tmp_plane_x = map->plane_x;
	map->dir_x = map->dir_x * cos(rot_spd) - map->dir_y * sin(rot_spd);
	map->dir_y = tmp_dir_x * sin(rot_spd) + map->dir_y * cos(rot_spd);
	map->plane_x = map->plane_x * cos(rot_spd) - map->plane_y * sin(rot_spd);
	map->plane_y = tmp_plane_x * sin(rot_spd) + map->plane_y * cos(rot_spd);
}
