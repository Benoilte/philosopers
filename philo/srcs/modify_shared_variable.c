/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shared_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:20:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/10 11:24:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_dead_flag_to_one(t_table *table)
{
	pthread_mutex_lock(&(table->locker->death));
	table->dead_flag = 1;
	pthread_mutex_unlock(&(table->locker->death));
}

void	set_meals_limit_reached_to_one(t_table *table)
{
	pthread_mutex_lock(&(table->locker->meals_limit_reached));
	table->meals_limit_reached = 1;
	pthread_mutex_unlock(&(table->locker->meals_limit_reached));
}

void	reset_last_meal_eaten(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meals));
	philo->last_meal_eaten = ms_actual_time();
	pthread_mutex_unlock(&(philo->meals));
}

void	add_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meals));
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&(philo->meals));
}
