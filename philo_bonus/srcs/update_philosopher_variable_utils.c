/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_philosopher_variable_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:34:23 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:31:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	reset_last_meal_eaten(t_philo *philo)
{
	sem_wait(philo->philo_locker->meals_flag);
	philo->last_meal_eaten = ms_actual_time();
	sem_post(philo->philo_locker->meals_flag);
}

void	add_meals_eaten(t_philo *philo)
{
	sem_wait(philo->philo_locker->meals_flag);
	philo->meals_eaten += 1;
	sem_post(philo->philo_locker->meals_flag);
}
