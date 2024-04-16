/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_philosopher_variable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:43:18 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 10:01:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	get_last_meal_eaten(t_philo *philo)
{
	size_t	last_meal_eaten;

	sem_wait(philo->philo_locker->meals);
	last_meal_eaten = philo->last_meal_eaten;
	sem_post(philo->philo_locker->meals);
	return (last_meal_eaten);
}

int	get_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	sem_wait(philo->philo_locker->meals);
	meals_eaten = philo->meals_eaten;
	sem_post(philo->philo_locker->meals);
	return (meals_eaten);
}

int	philo_is_still_alive(t_philo *philo)
{
	sem_wait(philo->philo_locker->run_condition);
	if (philo->is_dead)
	{
		sem_post(philo->philo_locker->run_condition);
		return (NO);
	}
	sem_post(philo->philo_locker->run_condition);
	return (YES);
}

int	philo_is_full(t_philo *philo)
{
	sem_wait(philo->philo_locker->run_condition);
	if (philo->is_full)
	{
		sem_post(philo->philo_locker->run_condition);
		return (YES);
	}
	sem_post(philo->philo_locker->run_condition);
	return (NO);
}

int	can_dinner_continue(t_philo *philo)
{
	sem_wait(philo->philo_locker->run_condition);
	if (philo->dinner_running)
	{
		sem_post(philo->philo_locker->run_condition);
		return (YES);
	}
	sem_post(philo->philo_locker->run_condition);
	return (NO);
}
