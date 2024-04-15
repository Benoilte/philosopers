/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philo_supervisor_action.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:57 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:41:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*philosopher_monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (dinner_is_not_finished(philo))
	{
		if (philo->table->meals_limit && philo_is_still_alive(philo)
			&& (philo_is_full(philo) == NO))
		{
			update_philo_if_he_is_full(philo);
			if (philo_is_full(philo))
				sem_post(philo->table->shared_locker->full);
		}
		if (philosopher_starving(philo))
			philo_die(philo);
	}
	return (NULL);
}

void	*stop_dinner_monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->table->shared_locker->stop);
	set_dinner_as_finished(philo);
	return (NULL);
}

int	philosopher_starving(t_philo *philo)
{
	if (ms_time_diff(get_last_meal_eaten(philo))
		>= (size_t)philo->time->time_to_die)
		return (YES);
	else
		return (NO);
}
