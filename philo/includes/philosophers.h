/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 14:45:24 by bebrandt         ###   ########.fr       */
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
	OK,
	ERROR
};

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
	SLEEP,
	EAT,
	THINK,
	TAKE_FORKS
};

typedef struct s_locker
{
	pthread_mutex_t	write;
	pthread_mutex_t	meal;
	pthread_mutex_t	last_meal;
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
	int				dead_philo;
	int				meals_limit;
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
t_philo		*init_all_philosophers(t_table *table);
t_philo		*init_one_philosophers(t_table *table, int id);

// operate_philo_lst.c

void		add_philo_to_philosophers(t_philo *philo, t_philo **philosophers);

// cleaning.c

void		clean_table(t_table *table);
void		clean_locker(t_locker *locker, int nbr_of_locker_to_del);
void		clean_all_philosophers(t_philo **philo);

// verbose.c

void		print_argument_definition(int arg);

// libft_utils.c

int			ft_atoi(const char *str);
long		ft_atoi_long(const char *str);
int			ft_isdigit(int c);

// test.c

void		print_data_structure(t_table *table);
void		print_table(t_table *table);
void		print_time(t_time *time);
void		print_philosophers(t_philo *philosophers);

#endif
