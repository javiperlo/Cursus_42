/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:34:31 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 20:10:45 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	all_digit(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int					i;
	unsigned long long	res;

	if (argc != 5 && argc != 6)
	{
		printf("%s", ERR_CMD);
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		res = ft_atol(argv[i]);
		if (i == 1 && res > 200)
		{
			printf(ERR_MAX);
			return (1);
		}
		if (res <= 0 || res > INT_MAX || !all_digit(argv[i]))
		{
			printf(ERR_ARGS);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[MAX_PHILOSOPHERS];
	pthread_mutex_t	forks[MAX_PHILOSOPHERS];

	if (check_argv(argc, argv) != 0)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atol(argv[1]));
	init_philo(philos, &program, forks, argv);
	create_threads(&program, forks);
	release_resources(NULL, &program, forks);
	return (0);
}
