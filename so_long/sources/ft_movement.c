/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:37:03 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:24:52 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int move_x, int move_y)
{
	if (game->map[game->player_y + move_y][game->player_x + move_x] != '1')
	{
		game->steps++;
		ft_write_moves(game->steps);
		put_sprite(game, game->player_x, game->player_y, EMPTY);
		put_sprite(game, game->player_x + move_x,
			game->player_y + move_y, PLAYER);
		if (game->map[game->player_y + move_y][game->player_x + move_x] == 'C')
		{
			game->items_count--;
			write (1, "🧪 Item Collected!\n", 22);
			if (game->items_count == 0)
				put_sprite(game, game->exit_x, game->exit_y, EXIT);
		}
		game->player_x = game->player_x + move_x;
		game->player_y = game->player_y + move_y;
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		else if (game->map[game->player_y][game->player_x] == 'E'
				&& game->items_count == 0)
			ft_game_result(game);
	}
}

int	press_key(int key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else if (key == W)
		move_player(game, 0, -1);
	else if (key == A)
		move_player(game, -1, 0);
	else if (key == S)
		move_player(game, 0, 1);
	else if (key == D)
		move_player(game, 1, 0);
	return (0);
}
