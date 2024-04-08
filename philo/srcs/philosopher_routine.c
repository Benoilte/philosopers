/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:00:38 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 18:47:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_routine_alone(t_table *table, int *status)
{
	t_philo	*philo;

	philo = table->first_philo;
	if (pthread_create(&(philo->thread), NULL, &routine_for_one, philo) != 0)
	{
		printf("Error: Failed to create philosopher %d thread\n", philo->id);
		table->dead_philo = 1;
		*status = EXIT_FAILURE;
		return ;
	}
}

void	start_routine_together(t_table *table, int *status)
{
	t_philo	*philo;
	int		i;

	i = 1;
	philo = table->first_philo;
	while (i <= table->nbr_philo)
	{
		if (pthread_create(&(philo->thread), NULL, &routine, philo) != 0)
		{
			printf("Error: Failed to create philosopher %d thread\n", philo->id);
			table->dead_philo = 1;
			*status = EXIT_FAILURE;
			return ;
		}
		philo = philo->next;
		i++;
	}
}

void	*routine_for_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->table->locker->write));
	print_philo(philo);
	pthread_mutex_unlock(&(philo->table->locker->write));
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->table->locker->write));
	print_philo(philo);
	pthread_mutex_unlock(&(philo->table->locker->write));
	return (NULL);
}
