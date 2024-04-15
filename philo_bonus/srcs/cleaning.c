/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 14:44:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*clean_all(t_table *table, t_parent *parent, t_philo *philo,
			int *status)
{
	clean_table(table, status);
	clean_parent(parent, status);
	clean_philo(philo, status);
	return (NULL);
}

void	*clean_table(t_table *table, int *status)
{
	if (table)
	{
		if (table->time)
			free(table->time);
		if (table->shared_locker)
			clean_shared_locker(table->shared_locker, 5, status);
		free(table);
	}
	return (NULL);
}

void	*clean_parent(t_parent *parent, int *status)
{
	if (parent)
	{
		if (parent->philosopher_pid)
			free(parent->philosopher_pid);
		if (parent->read_and_update)
			close_semaphore(parent->read_and_update, READ_AND_UPDATE, status);
		unlink_semaphore();
		free(parent);
	}
	return (NULL);
}

void	*clean_philo(t_philo *philo, int *status)
{
	if (philo)
	{
		if (philo->philo_locker)
			clean_philo_locker(philo->philo_locker, 2, status);
		philo->time = NULL;
		philo->table = NULL;
		free(philo);
	}
	return (NULL);
}
