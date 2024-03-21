/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/21 10:42:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	move_forks(t_philo *philo)
{
	if (philo->state == WANT_TO_EAT
		&& other_must_eat_first(philo->id,
			philo->shared->meals, philo->n_philo))
		return ;
	pthread_mutex_lock(&(philo->shared->mutex));
	if (philo->state == WANT_TO_EAT)
		take_forks(philo);
	else if (philo->state == WANT_TO_SLEEP)
		return_forks(philo);
	pthread_mutex_unlock(&(philo->shared->mutex));
}

int	other_must_eat_first(int philo_id, int *meals, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		if (meals[philo_id] > meals[i])
			return (1);
		i++;
	}
	return (0);
}

void	take_forks(t_philo *philo)
{
	if (philo->id == 0)
	{
		if ((philo->shared->forks)[philo->id]
			&& (philo->shared->forks)[philo->n_philo - 1])
		{
			(philo->shared->forks)[philo->id] = 0;
			(philo->shared->forks)[philo->n_philo - 1] = 0;
			philo->state = READY_TO_EAT;
			(philo->shared->meals)[philo->id] += 1;
			printf("timestamp_in_ms %d has taken a fork\n", philo->id + 1);
		}
	}
	else
	{
		if ((philo->shared->forks)[philo->id]
			&& (philo->shared->forks)[philo->id - 1])
		{
			(philo->shared->forks)[philo->id] = 0;
			(philo->shared->forks)[philo->id - 1] = 0;
			philo->state = READY_TO_EAT;
			(philo->shared->meals)[philo->id] += 1;
			printf("timestamp_in_ms %d has taken a fork\n", philo->id + 1);
		}
	}
}

void	return_forks(t_philo *philo)
{
	if (philo->id == 0)
	{
		(philo->shared->forks)[philo->id] = 1;
		(philo->shared->forks)[philo->n_philo - 1] = 1;
		printf("timestamp_in_ms %d has return forks\n", philo->id + 1);
	}
	else
	{
		(philo->shared->forks)[philo->id] = 1;
		(philo->shared->forks)[philo->id - 1] = 1;
		printf("timestamp_in_ms %d has return forks\n", philo->id + 1);
	}
}
