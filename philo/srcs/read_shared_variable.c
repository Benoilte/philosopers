/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shared_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:24:04 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 09:33:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_dead_flag(t_table *table)
{
	int	dead_flag;

	pthread_mutex_lock(&(table->locker->death));
	dead_flag = table->dead_flag;
	pthread_mutex_unlock(&(table->locker->death));
	return (dead_flag);
}

int	read_meals_limit_reached(t_table *table)
{
	int	meals_limit_reached;

	pthread_mutex_lock(&(table->locker->meals_limit_reached));
	meals_limit_reached = table->meals_limit_reached;
	pthread_mutex_unlock(&(table->locker->meals_limit_reached));
	return (meals_limit_reached);
}

int	read_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&(philo->meals));
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&(philo->meals));
	return (meals_eaten);
}

size_t	read_last_meals_eaten(t_philo *philo)
{
	size_t	last_meals_eaten;

	pthread_mutex_lock(&(philo->meals));
	last_meals_eaten = philo->last_meal_eaten;
	pthread_mutex_unlock(&(philo->meals));
	return (last_meals_eaten);
}

int	read_state(t_philo *philo)
{
	int	state;

	pthread_mutex_lock(&(philo->lock_state));
	state = philo->state;
	pthread_mutex_unlock(&(philo->lock_state));
	return (state);
}
