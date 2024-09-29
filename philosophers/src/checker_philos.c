/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:34:35 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 19:49:20 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->mutex_write);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("\033[1;38;2;96;168;235m%zums\033[0m\t \033[1;38;2;255;165;0m\
		[%d]\033[0m\t\033[1;38;2;238;232;224m%s\033[0m\n", time, id, str);
	pthread_mutex_unlock(philo->mutex_write);
}

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->mutex_meal);
	if (get_current_time() - philo->last_meal >= time_to_die)
		return (pthread_mutex_unlock(philo->mutex_meal), 1);
	pthread_mutex_unlock(philo->mutex_meal);
	return (0);
}

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].info.num_of_philos)
	{
		if (philosopher_dead(&philos[i], philos[i].info.time_to_die))
		{
			print_message("died 💀", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].mutex_dead);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].mutex_dead);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].info.num_times_to_eat == -1)
		return (0);
	while (i < philos[0].info.num_of_philos)
	{
		pthread_mutex_lock(philos[i].mutex_meal);
		if (philos[i].meals_eaten >= philos[i].info.num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].mutex_meal);
		i++;
	}
	if (finished_eating == philos[0].info.num_of_philos)
	{
		pthread_mutex_lock(philos[0].mutex_dead);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].mutex_dead);
		return (1);
	}
	return (0);
}

void	*philosopher_checker(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (ptr);
}
