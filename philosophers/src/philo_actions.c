/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:34:51 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 19:33:45 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	ft_think(t_philo *philo)
{
	print_message("is thinking ​💭​", philo, philo->id);
	if (philo->info.num_of_philos % 2 != 0)
		ft_usleep(philo, philo->info.time_to_eat * 2
			- philo->info.time_to_sleep);
}


void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping 💤​", philo, philo->id);
	ft_usleep(philo, philo->info.time_to_sleep);
}

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork 🍴", philo, philo->id);
	if (philo->id % 2)
		pthread_mutex_lock(philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork 🍴", philo, philo->id);
}

void	ft_eat(t_philo *philo)
{
	if (philo->info.num_of_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message("has taken a fork 🍴", philo, philo->id);
		ft_usleep(philo, philo->info.time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pick_forks(philo);
	print_message("is eating 🍜", philo, philo->id);
	pthread_mutex_lock(philo->mutex_meal);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->mutex_meal);
	ft_usleep(philo, philo->info.time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
