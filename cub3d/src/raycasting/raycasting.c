/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:26:24 by javperez          #+#    #+#             */
/*   Updated: 2024/08/13 21:19:54 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_delta_dist(t_map *map)
{	
	if (map->ray_dir_x == 0)
		map->delta_dist_x = INT_MAX; //Usar INT_MAX es una forma práctica de representar esta idea de "infinito" dentro del límite de lo que un entero puede almacenar.
	else
		map->delta_dist_x = fabs(1 / map->ray_dir_x); // fabs(1 / 0.66) = 1.5
	if (map->ray_dir_y == 0)
		map->delta_dist_y = INT_MAX;
	else
		map->delta_dist_y = fabs(1 / map->ray_dir_y); // fabs(1 / -1) = 1
}

void	get_step(t_map *map) //Esta funcion es la que avanza en nuestra cuadricula imaginaria por caada corte del rayo en el que estemos mirando
{
	if (map->ray_dir_x < 0)
	{
		map->step_x = -1;
		//LINK - 		Nos quedamos con la parte decimal
		map->side_dist_x = (map->pos_x - map->map_x) * map->delta_dist_x;
	}
	else
	{
		map->step_x = 1;
		//Calcula  la distancia inicial desde la posicion actual del
		//jugador hasta el primer cruce de una linea de la cuadricula en el eje X
		map->side_dist_x = (map->map_x + 1.0 - map->pos_x) * map->delta_dist_x;
	}
	if (map->ray_dir_y < 0)
	{
		map->step_y = -1;
		map->side_dist_y = (map->pos_y - map->map_y) * map->delta_dist_y;
	}
	else
	{
		map->step_y = 1;
		map->side_dist_y = (map->map_y + 1.0 - map->pos_y) * map->delta_dist_y;
	}
}

//ALGORITMO DDA
void	digital_differential_analyser(t_map *map) //Sumamos los steps anteriores y 
{
	int	wall;

	wall = 0;
	while (wall == 0) //Mientras que no toca una pared
	{
		if (map->side_dist_x < map->side_dist_y) //Si corta primero con el eje X entra
		{
			map->side_dist_x += map->delta_dist_x;
			map->map_x += map->step_x; //Suma una unidad si side_dist_x es menor que side_dist_y. Mirar dibujo
			map->wall_side = 0;
		}
		else //Si corta primero con el eje Y entra
		{
			map->side_dist_y += map->delta_dist_y;
			map->map_y += map->step_y;
			map->wall_side = 1;
		}
		if (map->map_tab[map->map_y][map->map_x] == '1')
			wall = 1;
	}
}

void	init_raycasting(t_map *map, int x)
{
	//POSICION [2, 5]
	//map_x es la entera y pos_x es el float
	//pos_x y pos_y al movernos, adquiere decimales
	map->map_x = map->pos_x; //Se queda con la parte entera
	map->map_y = map->pos_y;

	map->cam_x = 2 * x / (double)map->display_width - 1;  //Columna del rayo normalizada --> [-1, 1]

	map->ray_dir_x = map->dir_x + map->plane_x * map->cam_x; //Dirección del rayo en x --> 0 + (0.66 * 0.8) = 0.528
	map->ray_dir_y = map->dir_y + map->plane_y * map->cam_x; //Dirección del rayo en y --> -1 + (0 * 0.8) = -1

	//Dirección del rayo en x --> 0 + (0.66 * 0) = 0
	//Dirección del rayo en y --> -1 + (0 * 0) = -1

	//Dirección del rayo en x --> 0 + (0.66 * 1) = 0.66
	//Dirección del rayo en y --> -1 + (0 * 1) = -1

	//Dirección del rayo en x --> 0 + (0.66 * -1) = -0.66
	//Dirección del rayo en y --> -1 + (0 * -1) = -1

	//Dirección del rayo en x --> 0 + (0.66 * -0.5) = -0.33
	//Dirección del rayo en y --> -1 + (0 * -0.5) = -1
}

void	raycasting(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->display_width)
	{
		init_raycasting(map, x);
		get_delta_dist(map);
		get_step(map);
		digital_differential_analyser(map);
		/*
			Uso de map->perpwalldist:

			En el código proporcionado, se hace uso de la variable map->perpwalldist. Esta variable
			probablemente almacena la distancia perpendicular desde la posición del jugador hasta el
			punto de intersección del rayo con la pared.

			Al utilizar map->perpwalldist en lugar de la distancia directa del rayo, se asegura
			que las columnas se dibujen con la altura correcta, evitando la distorsión que
			ocurriría si simplemente se usara la distancia del rayo.
		*/
		if (map->wall_side == 0)
			map->perpwalldist = ((map->side_dist_x - map->delta_dist_x));
		else
			map->perpwalldist = ((map->side_dist_y - map->delta_dist_y));
		draw_column(map, x);
		x++;
	}
}