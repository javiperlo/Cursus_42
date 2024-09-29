/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:34:55 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 20:08:26 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_dead);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex_dead);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(philo->info.time_to_eat);
	while (!dead_loop(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (ptr);
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &philosopher_checker,
			program->philos) != 0)
		release_resources("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].info.num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread_id, NULL, &philo_routine,
				&program->philos[i]) != 0)
			release_resources("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		release_resources("Thread join error", program, forks);
	while (i < program->philos[0].info.num_of_philos)
	{
		if (pthread_join(program->philos[i].thread_id, NULL) != 0)
			release_resources("Thread join error", program, forks);
		i++;
	}
	return (0);
}
