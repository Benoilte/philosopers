/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/12 17:16:56 by bebrandt         ###   ########.fr       */
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
		return (clean_table(table));
	table->shared_locker = init_shared_locker(table->nbr_philo);
	if (!table->shared_locker)
		return (clean_table(table));
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
	time->start_time = 0;
	return (time);
}

t_shared_locker	*init_shared_locker(int nbr_philo)
{
	t_shared_locker	*shared_locker;

	shared_locker = (t_shared_locker *)malloc(sizeof(t_shared_locker));
	if (!shared_locker)
		return (NULL);
	shared_locker->print = sem_open(PRINT, O_CREAT, 0644, 1);
	if (semaphore_failed(shared_locker->forks, PRINT))
		clean_shared_locker(shared_locker, 0);
	shared_locker->forks = sem_open(FORKS, O_CREAT, 0644, nbr_philo);
	if (semaphore_failed(shared_locker->forks, FORKS))
		clean_shared_locker(shared_locker, 1);
	shared_locker->death = sem_open(DEATH, O_CREAT, 0644, 0);
	if (semaphore_failed(shared_locker->forks, DEATH))
		clean_shared_locker(shared_locker, 2);
	shared_locker->full = sem_open(FULL, O_CREAT, 0644, 0);
	if (semaphore_failed(shared_locker->forks, FULL))
		clean_shared_locker(shared_locker, 3);
	shared_locker->stop = sem_open(STOP, O_CREAT, 0644, 0);
	if (semaphore_failed(shared_locker->forks, STOP))
		clean_shared_locker(shared_locker, 4);
	return (shared_locker);
}

int	semaphore_failed(sem_t *sem, char *msg)
{
	if (sem == SEM_FAILED)
	{
		printf("Error: sem_open() FAILED to create %smsg\n", msg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
