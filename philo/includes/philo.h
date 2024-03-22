/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 23:19:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

enum
{
	WANT_TO_EAT,
	READY_TO_EAT,
	WANT_TO_SLEEP,
	WANT_TO_THINK
};

typedef struct s_data
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_limit;
	int				*forks;
	int				*meals;
	int				*run_simulation;
	size_t			*last_meal;
	struct timeval	start;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_forks;
	pthread_mutex_t	m_meal;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				state;
	struct timeval	last_meal;
	t_data			*shared;
}					t_philo;

// philo.c

int					arg_format_is_wrong(int argc, char **argv);
int					start_simulation(int argc, char **argv);
void				start_routine(t_data *shared, pthread_t *th);

// philo_utils.c

void				*routine(void *num);
void				print_log(int id, t_data *shared, char *msg,
						int msg_is_died);
void				clean(pthread_t *th, t_data *shared);
int					wait_thread_end(pthread_t *th, pthread_t monitor,
						t_data *shared);

// init.c

t_data				*new_data(int argc, char **argv);
int					init_data(t_data *shared, int n_philo);
void				fill_data_ptr(t_data *shared);
void				init_philo(t_philo *philo, t_data *shared, int i);

// monitor.c

void				*control_simulation(void *data);
int					meals_limit_is_reached(t_data *shared);
void				is_one_philosopher_starving(t_data *shared);

// state.c

void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
size_t				timestamp(struct timeval *start);
size_t				ft_time(struct timeval *time);

// state_utils.c

void				move_forks(t_philo *philo);
int					other_must_eat_first(t_philo *philo);
void				is_forks_available(t_philo *philo);
void				take_forks(t_philo *philo, int right_fork, int left_fork);
void				return_forks(t_philo *philo);

// ft_atoi.c

int					ft_atoi(const char *str);

// ft_isdigit.c

int					ft_isdigit(int c);

#endif
