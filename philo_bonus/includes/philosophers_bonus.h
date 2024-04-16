/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:37:11 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 22:39:34 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>

# define PRINT "/print"
# define FORKS "/forks"
# define DEATH "/death"
# define FULL "/full"
# define STOP "/stop"

# define PHILO_STATE "/philo_state"
# define MEALS "/meals"

# define READ_AND_UPDATE "/read_and_update"

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
	NO,
	YES
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
	PHILOSOPHER_IS_STILL_HUNGRY,
	PHILOSOPHER_IS_FULL
};

enum
{
	PHILOSOPHER_ALREADY_EAT_ENOUGH,
	PHILOSOPHER_DO_NOT_EAT_ENOUGH
};

enum
{
	PHILOSOPHER_IS_ALIVE,
	PHILOSOPHER_IS_DEAD
};

typedef struct s_parent
{
	int				nbr_philosophers_full;
	int				is_one_philosopher_die;
	int				is_simulation_stopped;
	pthread_t		death_supervisor;
	pthread_t		meals_eaten_supervisor;
	pid_t			*philosopher_pid;
	sem_t			*read_and_update;
	struct s_table	*table;
}					t_parent;

typedef struct s_time
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	size_t			start_time;
}					t_time;

typedef struct s_table
{
	int						nbr_philo;
	int						meals_limit;
	struct s_time			*time;
	struct s_shared_locker	*shared_locker;
}							t_table;

typedef struct s_shared_locker
{
	sem_t	*print;
	sem_t	*forks;
	sem_t	*death;
	sem_t	*full;
	sem_t	*stop;
}			t_shared_locker;

typedef struct s_philo_locker
{
	sem_t	*philo_state_flag;
	sem_t	*meals_flag;
}			t_philo_locker;

typedef struct s_philo
{
	int						id;
	int						state;
	int						meals_eaten;
	size_t					last_meal_eaten;
	int						is_dead;
	int						is_full;
	int						already_eat_enough;
	int						dinner_running;
	pthread_t				philosopher_supervisor;
	pthread_t				stop_dinner_supervisor;
	struct s_table			*table;
	struct s_time			*time;
	struct s_philo_locker	*philo_locker;
}							t_philo;

// philo.c

void			prep_philosophers_dinner(int argc, char **argv);
void			run_philosophers_dinner(t_table *table, t_parent *parent,
					t_philo *philosopher);
void			create_philosopher(t_table *table, t_parent *parent,
					t_philo *philosopher);
void			wait_the_end_of_philosophers_dinner(t_parent *parent);

// check_arg_input.c

int				arg_is_not_valid(int argc, char **argv);
int				arg_number_is_wrong(int argc);
int				arg_format_is_not_digit(int argc, char **argv);
int				arg_format_is_greater_than_int_max(int argc, char **argv);
int				arg_format_is_equal_to_zero(int argc, char **argv);

// init_lst.c

t_table			*init_table(int argc, char **argv);
t_time			*init_time(char **argv);
t_parent		*init_parent(t_table *table);
t_philo			*init_philosopher(t_table *table);

// init_lst_utils.c

t_shared_locker	*init_shared_locker(int nbr_philo);
t_philo_locker	*init_philo_locker(void);
int				init_semaphore_failed(sem_t *sem, char *msg);

// philosopher_routine.c

void			start_philosopher_routine(t_table *table, t_parent *parent,
					t_philo *philo, int *status);
void			start_routine_alone(t_philo *philo);
void			start_routine(t_philo *philo, int *status);
int				create_philo_supervisor(t_philo *philo, int *status);
void			wait_end_of_philo_supervisor(t_philo *philo, int *status);

// perform_philo_supervisor_action.c

void			*philosopher_monitoring(void *arg);
void			*stop_dinner_monitoring(void *arg);
int				philosopher_starving(t_philo *philo);

// perform_philosopher_action.c

void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
void			philo_die(t_philo *philo);

// perform_philosopher_action_utils.c

int				dinner_is_not_finished(t_philo *philo);
void			take_forks(t_philo *philo);
void			return_forks(t_philo *philo);

// perform_parent_action.c

void			start_parent_monitoring(t_parent *parent, int *status);
void			*death_monitoring(void *arg);
void			*meals_eaten_monitoring(void *arg);
void			set_stop_simulation(t_parent *parent);
void			wait_supervisors_end(t_parent *parent, int *status);

// read_philosopher_variable.c

size_t			get_last_meal_eaten(t_philo *philo);
int				get_meals_eaten(t_philo *philo);
int				philo_is_still_alive(t_philo *philo);
int				philo_is_full(t_philo *philo);
int				can_dinner_continue(t_philo *philo);

// update_philosopher_variable.c

void			modify_philo_state(t_philo *philo, int state);
void			set_philosopher_dead(t_philo *philo);
void			set_philosopher_full(t_philo *philo);
void			update_philo_if_he_is_full(t_philo *philo);
void			set_dinner_as_finished(t_philo *philo);

// update_philosopher_variable_utils.c

void			reset_last_meal_eaten(t_philo *philo);
void			add_meals_eaten(t_philo *philo);

// time.c

size_t			ms_actual_time(void);
size_t			ms_timestamp(size_t start);
size_t			ms_time(struct timeval *time);
size_t			ms_time_diff(size_t time);
void			ms_sleep(int ms);

// cleaning.c

void			*clean_all(t_table *table, t_parent *parent, t_philo *philo,
					int *status);
void			*clean_table(t_table *table, int *status);
void			*clean_parent(t_parent *parent, int *status);
void			*clean_philo(t_philo *philo, int *status);

// cleaning_utils.c

void			*clean_shared_locker(t_shared_locker *shared_locker,
					int nbr_locker, int *status);
void			*clean_philo_locker(t_philo_locker *philo_locker,
					int nbr_locker, int *status);
void			unlink_semaphore(void);
void			close_semaphore(sem_t *sem, char *msg, int *status);

// verbose.c

void			print_argument_definition(int arg);
void			print_philo_status(t_philo *philo);
void			print_log(t_philo *philo, char *msg);
void			print_dead_log(t_philo *philo, char *msg);

// libft_utils.c

int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
int				ft_isdigit(int c);

// test.c

void			print_structure(t_table *table, t_parent *parent,
					t_philo *philo);
void			print_table(t_table *table);
void			print_time(t_time *time);
void			print_parent(t_table *table, t_parent *parent);
void			print_philosophers(t_philo *philosophers);

#endif
