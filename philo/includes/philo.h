/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/21 15:04:14 by bebrandt         ###   ########.fr       */
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

typedef struct s_shared_var
{
	char			**argv;
	int				argc;
	int				*forks;
	int				*meals;
	int				*run_simulation;
	struct timeval	start;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_forks;
	pthread_mutex_t	m_meal;
}					t_shared_var;

typedef struct s_philo
{
	int				id;
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_limit;
	int				state;
	int				still_alive;
	struct timeval	state_change;
	struct timeval	last_meal;
	t_shared_var	*shared;
}					t_philo;

// philo.c

int					arg_format_is_wrong(int argc, char **argv);
int					start_simulation(int argc, char **argv);
void				create_thread(t_shared_var *shared, pthread_t *th, int i);
void				init_philo(t_philo *philo, t_shared_var *shared, int i);

// philo_utils.c

void				*routine(void *num);
void				print_log(t_philo *philo, char *msg);
void				clean(pthread_t *th, t_shared_var *shared);
int					wait_thread_ending(pthread_t *th, char **argv);

// init.c

t_shared_var		*new_shared_variable(int argc, char **argv);
int					init_shared_variable(t_shared_var *shared, int n_philo);

// state.c

void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
size_t				time_diff(struct timeval *start, struct timeval *end);

// state_utils.c

void				move_forks(t_philo *philo);
void				take_forks(t_philo *philo);
void				return_forks(t_philo *philo);
int					other_must_eat_first(int philo_id, int *meals, int n_philo);

// ft_atoi.c

int					ft_atoi(const char *str);

// ft_isdigit.c

int					ft_isdigit(int c);

#endif
