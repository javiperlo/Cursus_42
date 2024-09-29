/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:47:50 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:48:01 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_the_matrix(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i ++;
	}
	free(game->map);
	game->map = NULL;
}

int	close_window(t_game *game)
{
	free_the_matrix(game);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	ft_game_result(t_game *game)
{
	free_the_matrix(game);
	mlx_destroy_window(game->mlx, game->win);
	write (1, "You finish this level in ", 26);
	ft_write_moves(game->steps);
	write(1, "\nCan you beat it?\n", 18);
	exit(0);
}
