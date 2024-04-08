/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philosophers_action.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:17:26 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 23:57:39 by bebrandt         ###   ########.fr       */
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
		return_forks(philo);
		philo->state = WANT_TO_SLEEP;
	}
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
		philo->state = SLEEPING;
		select_log_msg(philo);
		philo->state = WANT_TO_EAT;
	}
}

void	philo_die(t_philo *philo)
{
	(void)philo;
}
