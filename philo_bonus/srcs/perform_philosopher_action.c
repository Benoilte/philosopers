/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philosopher_action.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:35:12 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:27:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_philo_state(philo, EATING);
		print_philo_status(philo);
		reset_last_meal_eaten(philo);
		ms_sleep(philo->time->time_to_eat);
		add_meals_eaten(philo);
		modify_philo_state(philo, WANT_TO_SLEEP);
	}
	return_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_philo_state(philo, SLEEPING);
		print_philo_status(philo);
		ms_sleep(philo->time->time_to_sleep);
		modify_philo_state(philo, WANT_TO_THINK);
	}
}

void	philo_think(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_philo_state(philo, THINKING);
		print_philo_status(philo);
		modify_philo_state(philo, WANT_TO_EAT);
	}
}

void	philo_die(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_philo_state(philo, DEAD);
		set_philosopher_dead(philo);
		print_philo_status(philo);
		sem_post(philo->table->shared_locker->death);
	}
}
