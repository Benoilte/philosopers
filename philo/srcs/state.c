/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:20:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/05 13:57:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->state == SLEEP)
		return ;
	if (*(philo->shared->run_simulation))
	{
		take_forks(philo);
		pthread_mutex_lock(&(philo->shared->m_last_meal));
		gettimeofday(&(philo->last_meal), NULL);
		(philo->shared->last_meal)[philo->id] = ft_time(&(philo->last_meal));
		pthread_mutex_unlock(&(philo->shared->m_last_meal));
		(philo->shared->meals)[philo->id] += 1;
		print_log(philo->id, philo->shared, "is eating", 0);
		ft_usleep(philo->shared->time_to_eat);
		philo->state = SLEEP;
	}
	return_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->shared->run_simulation == 0)
		return ;
	print_log(philo->id, philo->shared, "is sleeping", 0);
	ft_usleep(philo->shared->time_to_sleep);
	philo->state = THINK;
}

void	ft_think(t_philo *philo)
{
	if (philo->shared->run_simulation == 0)
		return ;
	print_log(philo->id, philo->shared, "is thinking", 0);
	philo->state = EAT;
}
