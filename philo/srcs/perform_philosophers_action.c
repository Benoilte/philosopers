/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philosophers_action.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:17:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 01:03:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		modify_last_meal_eaten(philo);
		modify_meals_eaten(philo);
		philo->state = EATING;
		select_log_msg(philo);
		ft_usleep(philo->time->time_to_eat);
		philo->state = WANT_TO_SLEEP;
	}
	return_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		philo->state = SLEEPING;
		select_log_msg(philo);
		ft_usleep(philo->time->time_to_sleep);
		philo->state = WANT_TO_THINK;
	}
}

void	philo_think(t_philo *philo)
{
	if (dinner_is_not_finished(philo))
	{
		philo->state = THINKING;
		select_log_msg(philo);
		philo->state = WANT_TO_EAT;
	}
}

void	philo_die(t_philo *philo)
{
	philo->state = DEAD;
	select_log_msg(philo);
}
