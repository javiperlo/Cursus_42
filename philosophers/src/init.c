/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:23:03 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 19:04:27 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	init_inputs(t_philo *philo, char **argv)
{
	philo->info.time_to_die = ft_atol(argv[2]);
	philo->info.time_to_eat = ft_atol(argv[3]);
	philo->info.time_to_sleep = ft_atol(argv[4]);
	philo->info.num_of_philos = ft_atol(argv[1]);
	if (argv[5])
		philo->info.num_times_to_eat = ft_atol(argv[5]);
	else
		philo->info.num_times_to_eat = -1;
}

void	init_philo(t_philo *philos, t_program *program, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < (int)ft_atol(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		init_inputs(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].mutex_write = &program->mutex_write;
		philos[i].mutex_dead = &program->mutex_dead;
		philos[i].mutex_meal = &program->mutex_meal;
		philos[i].dead = &program->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].info.num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->mutex_meal, NULL);
	pthread_mutex_init(&program->mutex_write, NULL);
	pthread_mutex_init(&program->mutex_dead, NULL);
}
