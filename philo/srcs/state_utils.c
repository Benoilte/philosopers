/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 14:44:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	move_forks(t_philo *philo)
{
	if (philo->state == WANT_TO_EAT && other_must_eat_first(philo))
		return ;
	pthread_mutex_lock(&(philo->shared->m_forks));
	if (philo->state == WANT_TO_EAT)
		take_forks(philo);
	else if (philo->state == WANT_TO_SLEEP)
		return_forks(philo);
	pthread_mutex_unlock(&(philo->shared->m_forks));
}

int	other_must_eat_first(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->shared->n_philo)
	{
		if ((philo->shared->last_meal)[philo->id]
			> (philo->shared->last_meal)[i])
			return (1);
		i++;
	}
	return (0);
}

void	take_forks(t_philo *philo)
{
	if (philo->shared->n_philo == 1)
		return ;
	if (philo->id == 0)
	{
		if ((philo->shared->forks)[philo->id]
			&& (philo->shared->forks)[philo->shared->n_philo - 1])
		{
			philo->state = READY_TO_EAT;
			gettimeofday(&(philo->state_change), NULL);
			(philo->shared->forks)[philo->id] = 0;
			print_log(philo->id, philo->shared, "has taken a fork");
			(philo->shared->forks)[philo->shared->n_philo - 1] = 0;
			print_log(philo->id, philo->shared, "has taken a fork");
		}
	}
	else
	{
		if ((philo->shared->forks)[philo->id]
			&& (philo->shared->forks)[philo->id - 1])
		{
			philo->state = READY_TO_EAT;
			gettimeofday(&(philo->state_change), NULL);
			(philo->shared->forks)[philo->id] = 0;
			print_log(philo->id, philo->shared, "has taken a fork");
			(philo->shared->forks)[philo->id - 1] = 0;
			print_log(philo->id, philo->shared, "has taken a fork");
		}
	}
}

void	return_forks(t_philo *philo)
{
	if (philo->id == 0)
	{
		(philo->shared->forks)[philo->id] = 1;
		(philo->shared->forks)[philo->shared->n_philo - 1] = 1;
	}
	else
	{
		(philo->shared->forks)[philo->id] = 1;
		(philo->shared->forks)[philo->id - 1] = 1;
	}
}
