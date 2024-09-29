/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:26:33 by javperez          #+#    #+#             */
/*   Updated: 2024/05/26 19:26:35 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color(t_map *map, int x, int y, int i)
{
	return (*(int *)(map->img[i].addr
		+ (y * map->img[i].line_len + x * (map->img[i].bpp / 8))));
}
