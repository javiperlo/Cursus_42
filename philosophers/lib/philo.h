/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javperez <javperez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:16:03 by javperez          #+#    #+#             */
/*   Updated: 2024/09/13 20:10:26 by javperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define MAX_PHILOSOPHERS 200
# define ERR_CMD "\033[1;37mArguments Error\033[0m\nEx : ./philo [nb_de_philo]\
[time_to_die] [time_to_eat] [time_to_sleep] [nb_time_must_eat]\
 ([nb_time_must_eat] is optional)\n"
# define ERR_MAX "Invalid number of philosophers. Máx : 200\n"
# define ERR_ARGS "All arguments must be set as greater than zero \
 and less than 2147483647.\n"

typedef struct s_info
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_of_philos;
	int				num_times_to_eat;
}					t_params;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			start_time;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*mutex_write;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*mutex_meal;
	t_params		info;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_meal;
	pthread_mutex_t	mutex_write;
	t_philo			*philos;
}					t_program;

void				init_program(t_program *program, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init_philo(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);
void				init_inputs(t_philo *philo, char **argv);
int					create_threads(t_program *program, pthread_mutex_t *forks);
void				*philosopher_checker(void *pointer);
void				*philo_routine(void *pointer);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);
unsigned long long	ft_atol(char *str);
int					ft_usleep(t_philo *philo, size_t milliseconds);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo, int id);
size_t				get_current_time(void);
void				release_resources(char *str, t_program *program,
						pthread_mutex_t *forks);

#endif
