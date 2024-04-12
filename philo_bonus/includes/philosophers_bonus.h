/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:37:11 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/12 17:14:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>

# define PRINT "/print"
# define FORKS "/forks"
# define DEATH "/death"
# define FULL "/full"
# define STOP "/stop"

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
	PHILOSOPHER_IS_ALIVE,
	PHILOSOPHER_IS_DEAD
};

typedef struct s_philosopher_parent
{
	int				nbr_philosophers_full;
	int				is_one_philosopher_die;
	pthread_t		death_supervisor;
	pthread_t		meals_eaten_supervisor;
	pid_t			*philosopher_pid;
	struct s_table	*table;
}					t_philosopher_parent;

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
	sem_t	*dinner_state_flag;
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
	pthread_t				philosopher_supervisor;
	pthread_t				stop_dinner_supervisor;
	struct s_table			*table;
	struct s_time			*time;
	struct s_philo_locker	*philo_locker;
}							t_philo;

// philo.c

void			prep_philosophers_dinner(int argc, char **argv);
void			run_philosophers_dinner(t_table *table,
					t_philosopher_parent *philosopher_parent, t_philo *philosopher);
// void		wait_the_end_of_philosophers_dinner(t_table *table, int *status);

// check_arg_input.c

int				arg_is_not_valid(int argc, char **argv);
int				arg_number_is_wrong(int argc);
int				arg_format_is_not_digit(int argc, char **argv);
int				arg_format_is_greater_than_int_max(int argc, char **argv);
int				arg_format_is_equal_to_zero(int argc, char **argv);

// init_lst.c

t_table			*init_table(int argc, char **argv);
t_time			*init_time(char **argv);
t_shared_locker	*init_shared_locker(int nbr_philo);
int				semaphore_failed(sem_t *sem, char *msg);

// init_philo_lst.c

// time.c

size_t			ms_actual_time(void);
size_t			ms_timestamp(size_t start);
size_t			ms_time(struct timeval *time);
size_t			ms_time_diff(size_t time);
void			ms_sleep(int ms);

// cleaning.c

void			*clean_table(t_table *table);
void			*clean_shared_locker(t_shared_locker *shared_locker, int nbr_locker);

// verbose.c

void			print_argument_definition(int arg);

// libft_utils.c

int				ft_atoi(const char *str);
long			ft_atoi_long(const char *str);
int				ft_isdigit(int c);

// test.c

#endif
