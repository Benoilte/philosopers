/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 20:36:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

enum
{
	NUMBER_OF_PHILOSOPHER = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	MEALS_LIMIT = 5
};

enum
{
	WANT_TO_SLEEP,
	WANT_TO_EAT,
	WANT_TO_THINK,
	SLEEPING,
	EATING,
	THINKING,
	TAKE_FORKS,
	DEAD
};

typedef struct s_locker
{
	pthread_mutex_t	write;
	pthread_mutex_t	meals_limit;
	pthread_mutex_t	meals_limit_reached;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	death;
}					t_locker;

typedef struct s_time
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	size_t			start_time;
}					t_time;

typedef struct s_table
{
	int				nbr_philo;
	int				dead_flag;
	int				meals_limit;
	int				meals_limit_reached;
	pthread_t		supervisor;
	struct s_time	*time;
	struct s_locker	*locker;
	struct s_philo	*first_philo;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				state;
	int				meals_eaten;
	size_t			last_meal_eaten;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
	struct s_time	*time;
	struct s_philo	*prev;
	struct s_philo	*next;
}					t_philo;

// philo.c

int			prep_philosophers_dinner(int argc, char **argv);
void		run_philosophers_dinner(t_table *table, int *status);
void		wait_the_end_of_philosophers_dinner(t_table *table, int *status);

// check_arg_input.c

int			arg_is_not_valid(int argc, char **argv);
int			arg_number_is_wrong(int argc);
int			arg_format_is_not_digit(int argc, char **argv);
int			arg_format_is_greater_than_int_max(int argc, char **argv);
int			arg_format_is_equal_to_zero(int argc, char **argv);

// init_lst.c

t_table		*init_table(int argc, char **argv);
t_time		*init_time(char **argv);
t_locker	*init_locker(void);
int			locker_mutex_init(t_locker *locker, pthread_mutex_t *mutex,
				char *msg, int nbr_of_locker);

// init_philo_lst.c

t_philo		*init_all_philosophers(t_table *table);
t_philo		*init_one_philosophers(t_table *table, int id);

// set_philosophers.c

void		add_philo_to_philosophers(t_philo *philo, t_philo **philosophers);
void		init_philosophers_dinner_start(t_table *table);

// philosopher_routine.c

void		start_routine_alone(t_table *table, int *status);
void		start_routine_together(t_table *table, int *status);
void		*routine_for_one(void *arg);
void		*routine(void *arg);

// supervisor_action.c

void		start_supervisor(t_table *table, int *status);
void		wait_the_end_of_supervisor(t_table *table, int *status);
void		*monitoring(void *arg);

// modify_shared_variable.c

void		modify_dead_flag(t_philo *philo);

// read_shared_variable.c

int			read_dead_flag(t_philo *philo);

// time.c

size_t		get_actual_time(void);
size_t		timestamp(size_t start);
size_t		ft_time(struct timeval *time);
size_t		ft_get_diff(size_t time);
void		ft_usleep(int ms);

// cleaning.c

void		clean_table(t_table *table, int *status);
void		clean_locker(t_locker *locker, int nbr_of_locker, int *status);
void		locker_mutex_destroy(pthread_mutex_t *mutex, char *msg,
				int *status);
void		clean_all_philosophers(t_philo **philo, int *status);

// verbose.c

void		print_argument_definition(int arg);
void		select_log_msg(t_philo *philo);
void		print_log_state(t_philo *philo, char *msg);

// libft_utils.c

int			ft_atoi(const char *str);
long		ft_atoi_long(const char *str);
int			ft_isdigit(int c);

// test.c

void		print_data_structure(t_table *table);
void		print_table(t_table *table);
void		print_time(t_time *time);
void		print_philosophers(t_philo *philosophers);
void		print_philo(t_philo *philo);

#endif
