/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_philosopher_variable.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:27:55 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:29:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	modify_philo_state(t_philo *philo, int state)
{
	philo->state = state;
}

void	set_philosopher_dead(t_philo *philo)
{
	sem_wait(philo->philo_locker->philo_state_flag);
	philo->is_dead = YES;
	sem_post(philo->philo_locker->philo_state_flag);
}

void	set_philosopher_full(t_philo *philo)
{
	sem_wait(philo->philo_locker->philo_state_flag);
	philo->is_full = YES;
	sem_post(philo->philo_locker->philo_state_flag);
}

void	update_philo_if_he_is_full(t_philo *philo)
{
	if (get_meals_eaten(philo) >= philo->table->meals_limit)
	{
		set_philosopher_full(philo);
		return ;
	}
	sem_post(philo->philo_locker->meals_flag);
}

void	set_dinner_as_finished(t_philo *philo)
{
	sem_wait(philo->philo_locker->philo_state_flag);
	philo->dinner_running = NO;
	sem_post(philo->philo_locker->philo_state_flag);
}
