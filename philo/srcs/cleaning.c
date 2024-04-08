/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:16:28 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 22:28:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_table(t_table *table, int *status)
{
	if (!table)
		return ;
	if (table->locker)
		clean_locker(table->locker, 5, status);
	if (table->time)
		free(table->time);
	if (table->first_philo)
		clean_all_philosophers(&(table->first_philo), status);
	free(table);
}

void	clean_locker(t_locker *locker, int nbr_of_locker, int *status)
{
	if (!locker)
		return ;
	if (nbr_of_locker >= 1)
		locker_mutex_destroy(&(locker->write), "write", status);
	if (nbr_of_locker >= 2)
		locker_mutex_destroy(&(locker->meals_limit), "meals_limit", status);
	if (nbr_of_locker >= 3)
		locker_mutex_destroy(&(locker->meals_limit_reached),
			"meals_limit_reached", status);
	if (nbr_of_locker >= 4)
		locker_mutex_destroy(&(locker->last_meal), "last_meal", status);
	if (nbr_of_locker >= 5)
		locker_mutex_destroy(&(locker->death), "death", status);
	free(locker);
}

void	locker_mutex_destroy(pthread_mutex_t *mutex, char *msg, int *status)
{
	if (pthread_mutex_destroy(mutex))
	{
		printf("Error: Failed to destroy %s mutex\n", msg);
		if (status)
			*status = EXIT_FAILURE;
	}
}

void	clean_all_philosophers(t_philo **philosophers, int *status)
{
	t_philo	*philo_to_free;
	t_philo	*next_philo;

	if (!*philosophers)
		return ;
	philo_to_free = *philosophers;
	if (philo_to_free->prev)
		philo_to_free->prev->next = NULL;
	*philosophers = NULL;
	while (philo_to_free)
	{
		next_philo = philo_to_free->next;
		philo_mutex_destroy(&(philo_to_free->left_fork),
			philo_to_free->id, "left_fork", status);
		philo_mutex_destroy(&(philo_to_free->meals),
			philo_to_free->id, "meals", status);
		philo_to_free->time = NULL;
		philo_to_free->table = NULL;
		free(philo_to_free);
		philo_to_free = next_philo;
	}
}

void	philo_mutex_destroy(pthread_mutex_t *mutex, int id, char *msg,
			int *status)
{
	if (pthread_mutex_destroy(mutex))
	{
		printf("Error: Failed to destroy %s mutex", msg);
		printf(" of philo %d\n", id);
		if (status)
			*status = EXIT_FAILURE;
	}
}
