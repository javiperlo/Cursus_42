/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:37:33 by javperez          #+#    #+#             */
/*   Updated: 2024/03/13 18:16:45 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define COLLECT	"./images/item.xpm"
# define EMPTY		"./images/empty.xpm"
# define EXIT		"./images/exit.xpm"
# define PLAYER		"./images/player.xpm"
# define WALL		"./images/wall.xpm"

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				**checker_map;
	int				checker_goals;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				player_count;
	int				items_count;
	int				exit_count;
	int				steps;
	char			*map_file_path;
}	t_game;

//	** ft_movement **
int		press_key(int key, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

//	** ft_draw_map **
void	draw_map(t_game *game);
void	put_sprite(t_game *game, int y, int x, char *sprite);

//	** ft_malloc_map **
void	ft_map_size(t_game *game);
void	ft_malloc_map(t_game *game);

//	** ft_check_map **
void	ft_check_outline(t_game *game);
void	ft_check_format_dotber(t_game *game);
void	ft_check_map_inputs(t_game *game);
void	ft_count_and_check_map_objects(t_game *game);
void	ft_check_if_possible(t_game *game);

// ** ft_checker_possible
void	iter_checker(t_game *game, int j, int i);
void	malloc_and_fill(t_game *game);
void	free_checker(t_game *game, int height);
void	ft_is_possible(t_game *game, int j, int i, int left);

// ** ft_finish **
void	ft_game_result(t_game *game);
int		close_window(t_game *game);
void	free_the_matrix(t_game *game);

// ** ft_utils **
char	*ft_strdup(char *str);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_itoa(unsigned int n);
void	ft_write_moves(unsigned int n);

#endif
