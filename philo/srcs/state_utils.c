/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 22:03:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	move_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->mutex));
	if (philo->state == WANT_TO_EAT)
		take_forks(philo);
	else if (philo->state == WANT_TO_SLEEP)
		return_forks(philo);
	pthread_mutex_unlock(&(philo->shared->mutex));
}

void	take_forks(t_philo *philo)
{
	if (philo->id == 0)
	{
		if ((philo->shared->forks)[philo->id] && (philo->shared->forks)[philo->n_philo - 1])
		{
			(philo->shared->forks)[philo->id] = 0;
			(philo->shared->forks)[philo->n_philo - 1] = 0;
			philo->state = READY_TO_EAT;
			printf("timestamp_in_ms %d has taken a fork\n", philo->id + 1);
		}
	}
	else
	{
		if ((philo->shared->forks)[philo->id] && (philo->shared->forks)[philo->id - 1])
		{
			(philo->shared->forks)[philo->id] = 0;
			(philo->shared->forks)[philo->id - 1] = 0;
			philo->state = READY_TO_EAT;
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
