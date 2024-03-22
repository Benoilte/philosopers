/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 17:10:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	move_forks(t_philo *philo)
{
	if (philo->state == WANT_TO_EAT && other_must_eat_first(philo))
		return ;
	pthread_mutex_lock(&(philo->shared->m_forks));
	if (philo->state == WANT_TO_EAT)
		is_forks_available(philo);
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

void	is_forks_available(t_philo *philo)
{
	int	*forks;

	if (philo->shared->n_philo == 1)
		return ;
	forks = philo->shared->forks;
	if (philo->id == 0)
	{
		if (forks[philo->id] && forks[philo->shared->n_philo - 1])
			take_forks(philo, philo->shared->n_philo - 1, philo->id);
	}
	else
	{
		if (forks[philo->id] && forks[philo->id - 1])
			take_forks(philo, philo->id - 1, philo->id);
	}
}

void	take_forks(t_philo *philo, int right_fork, int left_fork)
{
	philo->state = READY_TO_EAT;
	gettimeofday(&(philo->state_change), NULL);
	(philo->shared->forks)[left_fork] = 0;
	print_log(philo->id, philo->shared, "has taken a fork", 0);
	(philo->shared->forks)[right_fork] = 0;
	print_log(philo->id, philo->shared, "has taken a fork", 0);
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
