/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:22 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/26 18:38:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
// # include <type.h>

enum
{
	WANT_TO_EAT,
	READY_TO_EAT,
	WANT_TO_SLEEP,
	WANT_TO_THINK
};

enum
{
	FORMAT_SUCCESS,
	FORMAT_FAILURE,
};

enum
{
	SEMAPHORES_SUCCESS,
	SEMAPHORES_FAILURE,
};

typedef struct s_philo
{
	int				id;
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_limit;
	int				state;
	int				meals;
	size_t			last_meal;
	struct timeval	start;
}					t_philo;

# define LOCK_WRITE "./sem_write"

# define LOCK_FORKS "./sem_forks"

// philo_bonus.c

int					arg_format_is_wrong(int argc, char **argv);
int					start_simulation(int argc, char **argv);
int					create_philosopher(t_philo *philo, pid_t *pid);

// philo_bonus_utils.c

void				print_log(t_philo *philo, char *msg, sem_t *sem_write);
size_t				timestamp(struct timeval *start);
size_t				ft_time(struct timeval *time);
void				clean(t_philo *philo);

// routine.c

int 				start_routine(t_philo *philo);

// init.c

t_philo				*init_philo(int argc, char **argv);
void				init_pid_tab(pid_t *pid, int count);
int					init_semaphore(t_philo *philo, sem_t *sem_forks, sem_t *sem_write);

// ft_atoi.c

int					ft_atoi(const char *str);

#endif
