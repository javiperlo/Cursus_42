/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:04:10 by javperez          #+#    #+#             */
/*   Updated: 2024/03/12 19:17:07 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_sprite(t_game *game, int y, int x, char *sprite)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, sprite, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, y * 64, x * 64);
}

void	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			if (game->map[j][i] == '1')
				put_sprite(game, i, j, WALL);
			else
				put_sprite(game, i, j, EMPTY);
			if (game->map[j][i] == 'C')
				put_sprite(game, i, j, COLLECT);
			else if (game->map[j][i] == 'P')
				put_sprite(game, i, j, PLAYER);
			j++;
		}
		i++;
	}
}
