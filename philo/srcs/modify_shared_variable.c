/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shared_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:20:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 23:46:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	modify_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->locker->death));
	philo->table->dead_flag = 1;
	pthread_mutex_unlock(&(philo->table->locker->death));
}

void	modify_last_meal_eaten(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meals));
	philo->last_meal_eaten = get_actual_time();
	pthread_mutex_unlock(&(philo->meals));
}

void	modify_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&(philo->meals));
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&(philo->meals));
}
