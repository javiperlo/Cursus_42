/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:27:23 by javperez          #+#    #+#             */
/*   Updated: 2024/05/26 19:27:24 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	else if (keycode == KEY_W)
		move(map, map->dir_x * map->speed, map->dir_y * map->speed, '+');
	else if (keycode == KEY_S)
		move(map, map->dir_x * map->speed, map->dir_y * map->speed, '-');
	else if (keycode == KEY_A)
		move(map, map->plane_x * map->speed, map->plane_y * map->speed, '-');
	else if (keycode == KEY_D)
		move(map, map->plane_x * map->speed, map->plane_y * map->speed, '+');
	else if ((keycode == KEY_L && (map->p_dir == 'N' || map->p_dir == 'S'))
		|| (keycode == KEY_R && (map->p_dir == 'E' || map->p_dir == 'W')))
		rotate(map, -map->rot_speed);
	else if ((keycode == KEY_L && (map->p_dir == 'E' || map->p_dir == 'W'))
		|| (keycode == KEY_R && (map->p_dir == 'N' || map->p_dir == 'S')))
		rotate(map, map->rot_speed);
	return (0);
}

int	mouse_rotate_hook(int x, int y, t_map *map)
{
	(void)y;
	if (map->p_dir == 'N' || map->p_dir == 'S')
	{
		if (x > (int)(map->display_width / 1.2))
			rotate(map, map->rot_speed / 3);
		else if (x < map->display_width / 6)
			rotate(map, -map->rot_speed / 3);
	}
	else
	{
		if (x > (int)(map->display_width / 1.2))
			rotate(map, -map->rot_speed / 3);
		else if (x < map->display_width / 6)
			rotate(map, map->rot_speed / 3);
	}
	return (0);
}
