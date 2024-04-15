/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 10:22:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*clean_all(t_table *table, t_parent *parent, t_philo *philo)
{
	clean_table(table);
	clean_parent(parent);
	clean_philo(philo);
	return (NULL);
}

void	*clean_table(t_table *table)
{
	if (table)
	{
		if (table->time)
			free(table->time);
		if (table->shared_locker)
			clean_shared_locker(table->shared_locker, 5);
		free(table);
	}
	return (NULL);
}

void	*clean_parent(t_parent *parent)
{
	if (parent)
	{
		if (parent->philosopher_pid)
			free(parent->philosopher_pid);
		free(parent);
	}
	return (NULL);
}

void	*clean_philo(t_philo *philo)
{
	if (philo)
	{
		if (philo->philo_locker)
			clean_philo_locker(philo->philo_locker, 2);
		philo->time = NULL;
		philo->table = NULL;
		free(philo);
	}
	return (NULL);
}
