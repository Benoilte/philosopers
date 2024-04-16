/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 09:34:29 by bebrandt         ###   ########.fr       */
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
	READY_TO_EAT,
	SLEEPING,
	EATING,
	THINKING,
	TAKE_FORKS,
	DEAD
};

enum
{
	DINNER_IS_FINISHED,
	DINNER_CONTINUE
};

enum
{
	PHILOSOPHERS_ARE_STILL_HUNGRY,
	ALL_PHILOSOPHER_EAT_ENOUGH
};

enum
{
	ALL_PHILOSOPHER_ARE_ALIVE,
	ONE_PHILOSOPHER_IS_DEAD
};

typedef struct s_locker
{
	pthread_mutex_t	print;
	pthread_mutex_t	meals_limit_reached;
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
	pthread_mutex_t	meals;
	pthread_mutex_t	lock_state;
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
int			philo_mutex_init(t_philo *philo, int id);
void		print_error_to_init_philo_mutex(char *msg, int id);

// set_philosophers.c

void		add_philo_to_philosophers(t_philo *philo, t_philo **philosophers);
void		set_philosophers_dinner_start(t_table *table);
void		modify_philo_state(t_philo *philo, int state);

// philosopher_routine.c

void		start_routine_alone(t_table *table, int *status);
void		start_routine_together(t_table *table, int *status);
void		*routine_for_one(void *arg);
void		*routine(void *arg);
int			dinner_is_not_finished(t_philo *philo);

// manage_philosophers_forks.c

void		take_forks(t_philo *philo);
void		return_forks(t_philo *philo);

// perform_philosophers_action.c

void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_die(t_philo *philo);

// supervisor_action.c

void		start_supervisor(t_table *table, int *status);
void		wait_the_end_of_supervisor(t_table *table, int *status);
void		*monitoring(void *arg);
int			meals_limit_is_reached(t_table *table);
int			one_philosopher_starve(t_table *table);

// modify_shared_variable.c

void		set_dead_flag_to_one(t_table *table);
void		set_meals_limit_reached_to_one(t_table *table);
void		reset_last_meal_eaten(t_philo *philo);
void		add_meals_eaten(t_philo *philo);

// read_shared_variable.c

int			read_dead_flag(t_table *table);
int			read_meals_limit_reached(t_table *table);
int			read_meals_eaten(t_philo *philo);
size_t		read_last_meals_eaten(t_philo *philo);
int			read_state(t_philo *philo);

// time.c

size_t		ms_actual_time(void);
size_t		ms_timestamp(size_t start);
size_t		ms_time(struct timeval *time);
size_t		ms_time_diff(size_t time);
void		ms_sleep(int ms);

// cleaning.c

void		clean_table(t_table *table, int *status);
void		clean_locker(t_locker *locker, int nbr_of_locker, int *status);
void		locker_mutex_destroy(pthread_mutex_t *mutex, char *msg,
				int *status);
void		clean_all_philosophers(t_philo **philo, int *status);
void		philo_mutex_destroy(pthread_mutex_t *mutex, int id, char *msg,
				int *status);

// verbose.c

void		print_argument_definition(int arg);
void		print_philo_status(t_philo *philo);
void		print_log(t_philo *philo, char *msg);
void		print_dead_log(t_philo *philo, char *msg);

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
