/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:20:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 13:08:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	while (philo->state == WANT_TO_EAT)
	{
		move_forks(philo);
	}
	gettimeofday(&(philo->last_meal), NULL);
	print_log(philo, "is eating");
	(philo->shared->meals)[philo->id] += 1;
	usleep((philo->shared->time_to_eat) * 1000);
	philo->state = WANT_TO_SLEEP;
	gettimeofday(&(philo->state_change), NULL);
	move_forks(philo);
}

void	ft_sleep(t_philo *philo)
{
	print_log(philo, "is sleeping");
	usleep((philo->shared->time_to_sleep) * 1000);
	philo->state = WANT_TO_THINK;
	gettimeofday(&(philo->state_change), NULL);
}

void	ft_think(t_philo *philo)
{
	print_log(philo, "is thinking");
	philo->state = WANT_TO_EAT;
	gettimeofday(&(philo->state_change), NULL);
}

size_t	time_diff(struct timeval *start, struct timeval *end)
{
	// size_t	sec;
	// size_t	usec;

	// sec = (end->tv_sec - start->tv_sec) * 1000;
	// usec = (end->tv_usec - start->tv_usec) / 1000;
	return (ft_time(end) - ft_time(start));
}

size_t	ft_time(struct timeval *time)
{
	size_t	sec;
	size_t	usec;

	sec = time->tv_sec * 1000;
	usec = time->tv_usec / 1000;
	return (sec + usec);
}
