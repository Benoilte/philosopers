/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:37:11 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 13:54:32 by bebrandt         ###   ########.fr       */
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

// init_philo_lst.c


// time.c

size_t		get_actual_time(void);
size_t		timestamp(size_t start);
size_t		ft_time(struct timeval *time);
size_t		ft_get_diff(size_t time);
void		ft_usleep(int ms);

// cleaning.c

// verbose.c

void	    print_argument_definition(int arg);

// libft_utils.c

int			ft_atoi(const char *str);
long		ft_atoi_long(const char *str);
int			ft_isdigit(int c);

// test.c


#endif