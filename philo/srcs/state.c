/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:20:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 14:31:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->shared->run_simulation == 0)
		return ;
	while (philo->state == WANT_TO_EAT && *(philo->shared->run_simulation))
	{
		move_forks(philo);
	}
	gettimeofday(&(philo->last_meal), NULL);
	(philo->shared->last_meal)[philo->id] = ft_time(&(philo->last_meal));
	if (philo->shared->run_simulation == 0)
		return ;
	print_log(philo->id, philo->shared, "is eating");
	(philo->shared->meals)[philo->id] += 1;
	usleep((philo->shared->time_to_eat) * 1000);
	philo->state = WANT_TO_SLEEP;
	gettimeofday(&(philo->state_change), NULL);
	move_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->shared->run_simulation == 0)
		return ;
	print_log(philo->id, philo->shared, "is sleeping");
	usleep((philo->shared->time_to_sleep) * 1000);
	philo->state = WANT_TO_THINK;
	gettimeofday(&(philo->state_change), NULL);
}

void	ft_think(t_philo *philo)
{
	if (philo->shared->run_simulation == 0)
		return ;
	print_log(philo->id, philo->shared, "is thinking");
	philo->state = WANT_TO_EAT;
	gettimeofday(&(philo->state_change), NULL);
}

size_t	timestamp(struct timeval *start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (ft_time(&now) - ft_time(start));
}

size_t	ft_time(struct timeval *time)
{
	size_t	sec;
	size_t	usec;

	sec = time->tv_sec * 1000;
	usec = time->tv_usec / 1000;
	return (sec + usec);
}
