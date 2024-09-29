/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:36:34 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 19:41:10 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_player_and_exit_position(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			if (game->map[j][i] == 'E')
			{
				game->exit_x = i;
				game->exit_y = j;
			}
			i ++;
		}
		j ++;
	}
}

void	ft_init_data(t_game *game, char *name)
{
	game->height = 0;
	game->width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->player_count = 0;
	game->items_count = 0;
	game->exit_count = 0;
	game->steps = 0;
	game->map_file_path = name;
}

void	ft_general_check(t_game *game)
{
	ft_check_outline(game);
	ft_check_format_dotber(game);
	ft_check_map_inputs(game);
	ft_count_and_check_map_objects(game);
	ft_check_if_possible(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write (1, "Error!\nExpected one parameter\n", 30);
		exit (1);
	}
	ft_init_data(&game, argv[1]);
	ft_map_size(&game);
	if (game.height == game.width)
	{
		write (1, "Error!\nMap not Rectangular\n", 27);
		exit (1);
	}
	ft_malloc_map(&game);
	ft_general_check(&game);
	ft_get_player_and_exit_position(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.height * 64, "so_long");
	draw_map(&game);
	mlx_hook(game.win, 2, 0, press_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
}
