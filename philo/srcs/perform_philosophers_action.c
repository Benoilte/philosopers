/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philosophers_action.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:17:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 11:28:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_last_meal_eaten(philo);
		modify_meals_eaten(philo);
		modify_philo_state(philo, EATING);
		print_philo_status(philo);
		ft_usleep(philo->time->time_to_eat);
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
		ft_usleep(philo->time->time_to_sleep);
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
		modify_dead_flag(philo->table);
		modify_philo_state(philo, DEAD);
		print_philo_status(philo);
	}
}
