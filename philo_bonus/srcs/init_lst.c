/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:16:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nbr_philo = ft_atoi(argv[NUMBER_OF_PHILOSOPHER]);
	table->meals_limit = 0;
	if (argc == 6)
		table->meals_limit = ft_atoi(argv[MEALS_LIMIT]);
	table->time = NULL;
	table->shared_locker = NULL;
	table->time = init_time(argv);
	if (!table->time)
		return (clean_table(table, NULL));
	unlink_semaphore();
	table->shared_locker = init_shared_locker(table->nbr_philo);
	if (!table->shared_locker)
		return (clean_table(table, NULL));
	return (table);
}

t_time	*init_time(char **argv)
{
	t_time	*time;

	time = (t_time *)malloc(sizeof(t_time));
	if (!time)
		return (NULL);
	time->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	time->time_to_eat = ft_atoi(argv[TIME_TO_EAT]);
	time->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	time->start_time = ms_actual_time();
	return (time);
}

t_parent	*init_parent(t_table *table)
{
	t_parent	*parent;

	parent = (t_parent *)malloc(sizeof(t_parent));
	if (!parent)
		return (NULL);
	parent->philosopher_pid = NULL;
	parent->read_and_update = NULL;
	parent->read_and_update = sem_open(READ_AND_UPDATE, O_CREAT, 0644, 1);
	if (init_semaphore_failed(parent->read_and_update, READ_AND_UPDATE))
		return (clean_parent(parent, NULL));
	parent->philosopher_pid = (pid_t *)malloc(sizeof(pid_t) * table->nbr_philo);
	if (!parent->philosopher_pid)
		return (clean_parent(parent, NULL));
	memset(parent->philosopher_pid, 0, table->nbr_philo * sizeof(pid_t));
	parent->nbr_philosophers_full = 0;
	parent->is_one_philosopher_die = NO;
	parent->is_simulation_stopped = NO;
	parent->table = table;
	return (parent);
}

t_philo	*init_philosopher(t_table *table)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_locker = init_philo_locker();
	if (!philo->philo_locker)
		return (clean_philo(philo, NULL));
	philo->id = 1;
	philo->state = WANT_TO_SLEEP;
	philo->meals_eaten = 0;
	philo->last_meal_eaten = ms_actual_time();
	philo->is_dead = NO;
	philo->is_full = NO;
	philo->dinner_running = YES;
	philo->table = table;
	philo->time = table->time;
	return (philo);
}
