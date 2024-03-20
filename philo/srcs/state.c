/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:20:59 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 21:55:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	while (philo->state == WANT_TO_EAT)
	{
		move_forks(philo);
		usleep(1000000);
	}
	pthread_mutex_lock(&(philo->shared->mutex));
	printf("timestamp_in_ms %d is eating\n", philo->id + 1);
	pthread_mutex_unlock(&(philo->shared->mutex));
	usleep(ft_atoi((philo->shared->argv)[2]) * 1000);
	philo->state = WANT_TO_SLEEP;
	move_forks(philo);
	usleep(1000000);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->mutex));
	printf("timestamp_in_ms %d is sleeping\n", philo->id + 1);
	pthread_mutex_unlock(&(philo->shared->mutex));
	philo->state = WANT_TO_THINK;
}

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->mutex));
	printf("timestamp_in_ms %d is thinking\n", philo->id + 1);
	pthread_mutex_unlock(&(philo->shared->mutex));
	philo->state = WANT_TO_EAT;
}
