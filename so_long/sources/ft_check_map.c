/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:27:53 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:38:59 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_outline(t_game *game)
{
	int		i;
	int		err;

	i = 0;
	err = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			err = 1;
		i++;
	}
	if (err != 0)
	{
		write(2, "Error!\nMap outline bad\n", 24);
		exit (1);
	}
}

void	ft_check_format_dotber(t_game *game)
{
	int		len_of_file;

	len_of_file = ft_strlen(game->map_file_path);
	if (ft_strncmp(".ber", &game->map_file_path[len_of_file - 4], 4) != 0)
	{
		write(2, "Error!\nBad extension\n", 21);
		exit (1);
	}
}

void	ft_check_map_inputs(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] != '1' && game->map[j][i] != '0'
				&& game->map[j][i] != 'C' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'E')
			{
				write(2, "Error!\nBad map inputs\n", 22);
				exit (1);
			}
			else
				i++;
		}
		j++;
	}
}

void	ft_count_and_check_map_objects(t_game *game)
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
				game->player_count++;
			if (game->map[j][i] == 'C')
				game->items_count++;
			if (game->map[j][i] == 'E')
				game->exit_count++;
			i ++;
		}
		j ++;
	}
	if (game->player_count != 1 || game->items_count < 1
		|| game->exit_count != 1)
	{
		write(2, "Error!\nBad map inputs\n", 22);
		exit (1);
	}
}

void	ft_check_if_possible(t_game *game)
{
	int		player_coords[2];
	int		total_goals;
	int		row;
	int		col;

	player_coords [0] = -1;
	player_coords [1] = -1;
	total_goals = 0;
	col = -1;
	while (game->map[++col])
	{
		row = -1;
		while (game->map[col][++row])
		{
			if (game->map[col][row] == 'P')
			{
				player_coords[0] = row;
				player_coords[1] = col;
			}
			else if (game->map[col][row] == 'E' || game->map[col][row] == 'C')
				total_goals ++;
		}
	}
	ft_is_possible(game, player_coords[1], player_coords[0], total_goals);
}
