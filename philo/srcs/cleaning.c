/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:16:28 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 15:05:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_table(t_table *table)
{
	if (!table)
		return ;
	if (table->locker)
		clean_locker(table->locker, 3);
	if (table->time)
		free(table->time);
	if (table->first_philo)
		clean_all_philosophers(&(table->first_philo));
	free(table);
}

void	clean_locker(t_locker *locker, int nbr_of_locker_to_del)
{
	if (!locker)
		return ;
	if (nbr_of_locker_to_del >= 1)
	{
		if (pthread_mutex_destroy(&(locker->write)))
			printf("Error: Failed to destroy write mutex\n");
	}
	if (nbr_of_locker_to_del >= 2)
	{
		if (pthread_mutex_destroy(&(locker->meal)))
			printf("Error: Failed to destroy meal mutex\n");
	}
	if (nbr_of_locker_to_del >= 3)
	{
		if (pthread_mutex_destroy(&(locker->last_meal)))
			printf("Error: Failed to destroy last_meal mutex\n");
	}
	free(locker);
}

void	clean_all_philosophers(t_philo **philo)
{
	t_philo	*philo_to_free;
	t_philo	*next_philo;

	if (!*philo)
		return ;
	philo_to_free = *philo;
	if (philo_to_free->prev)
		philo_to_free->prev->next = NULL;
	*philo = NULL;
	while (philo_to_free)
	{
		next_philo = philo_to_free->next;
		if (pthread_mutex_destroy(&(philo_to_free->left_fork)))
		{
			printf("Error: Failed to destroy left_fork mutex");
			printf(" of philo %d\n", philo_to_free->id);
		}
		philo_to_free->time = NULL;
		philo_to_free->table = NULL;
		free(philo_to_free);
		philo_to_free = next_philo;
	}
}
