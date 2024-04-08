/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shared_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:24:04 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 23:22:38 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_dead_flag(t_philo *philo)
{
	int	dead_flag;

	pthread_mutex_lock(&(philo->table->locker->death));
	dead_flag = philo->table->dead_flag;
	pthread_mutex_unlock(&(philo->table->locker->death));
	return (dead_flag);
}

int	read_meals_limit_reached(t_philo *philo)
{
	int	meals_limit_reached;

	pthread_mutex_lock(&(philo->table->locker->meals_limit_reached));
	meals_limit_reached = philo->table->meals_limit_reached;
	pthread_mutex_unlock(&(philo->table->locker->meals_limit_reached));
	return (meals_limit_reached);
}
