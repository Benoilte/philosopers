/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 20:49:45 by bebrandt         ###   ########.fr       */
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
	int				*all_alive;
	struct timeval	start;
	pthread_mutex_t	mutex;
}					t_shared_var;

typedef struct s_philo
{
	int				id;
	int				n_philo;
	int				state;
	int				still_alive;
	struct timeval	state_change;
	struct timeval	last_meal;
	t_shared_var	*shared;
}					t_philo;

// philo.c

int					args_are_wrong(int argc, char **argv);
int					simulation(int argc, char **argv);
void				create_thread(t_shared_var *shared, pthread_t *th, int i);
int					wait_thread_ending(pthread_t *th, char **argv);

// philo_utils.c

void				clean(pthread_t *th, t_shared_var *shared);
void				*routine(void *num);

// shared_variable.c

int					malloc_shared_variable(t_shared_var *shared, int n_philo);
t_shared_var		*new_shared_variable(int argc, char **argv);

// state.c

void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);

// state.c

void				move_forks(t_philo *philo);
void				take_forks(t_philo *philo);
void				return_forks(t_philo *philo);

// ft_atoi.c

int					ft_atoi(const char *str);

// ft_isdigit.c

int					ft_isdigit(int c);

#endif
