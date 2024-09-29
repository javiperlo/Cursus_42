/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:28:03 by javperez          #+#    #+#             */
/*   Updated: 2024/05/26 19:28:06 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*mlx_img;
	char	*path;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	t_img	img[5];
	t_img	minimap;
	int		display_width;
	int		display_height;

	char	**map_tab;
	int		width_map;
	int		height_map;

	char	p_dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	int		rgb_floor[3];
	int		rgb_sky[3];

	char	*line;
	char	*map_line;

	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	double	ray_dir_x;
	double	ray_dir_y;
	double	cam_x;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwalldist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		wall_side;
	int		wall_dist;
	int		size_line;
	int		start_line;
	int		end_line;
	int		start;
	int		end;
	double	speed;
	double	rot_speed;

}	t_map;

#endif