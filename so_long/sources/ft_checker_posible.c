/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_posible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:22:56 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:15:53 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	malloc_and_fill(t_game *game)
{
	int		i;
	int		j;

	game->checker_map = malloc(sizeof(int *) * game->height);
	i = 0;
	while (i < game->height)
	{
		game->checker_map[i] = malloc(sizeof(int) * game->width);
		j = 0;
		while (j < game->width)
		{
			game->checker_map[i][j] = 0;
			j ++;
		}
		i ++;
	}
}

void	free_checker(t_game *game, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(game->checker_map[i]);
		i ++;
	}
	free(game->checker_map);
	game->checker_map = NULL;
}

void	iter_checker(t_game *game, int j, int i)
{
	if (game->checker_goals == 0)
		return ;
	if (game->checker_map[j][i] == 0 && game->map[j][i] != '1')
	{
		game->checker_map[j][i] = 1;
		if (game->map[j][i] == 'C' || game->map[j][i] == 'E')
			game->checker_goals--;
		iter_checker(game, j + 1, i);
		iter_checker(game, j - 1, i);
		iter_checker(game, j, i + 1);
		iter_checker(game, j, i - 1);
	}
}

void	ft_is_possible(t_game *game, int j, int i, int left)
{
	game->checker_goals = left;
	malloc_and_fill(game);
	iter_checker(game, j, i);
	if (game->checker_goals != 0)
	{
		write(2, "Error!\nMap is imposible\n", 24);
		free_checker(game, game->height);
		exit(1);
	}
	free_checker(game, game->height);
}
