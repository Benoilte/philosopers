/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_philosopher_action_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:41:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 18:35:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	dinner_is_not_finished(t_philo *philo)
{
	if (philo_is_still_alive(philo) && can_dinner_continue(philo))
		return (DINNER_CONTINUE);
	else
		return (DINNER_IS_FINISHED);
}

void	take_forks(t_philo *philo)
{
	sem_wait(philo->table->shared_locker->forks);
	modify_philo_state(philo, TAKE_FORKS);
	print_philo_status(philo);
	sem_wait(philo->table->shared_locker->forks);
	modify_philo_state(philo, TAKE_FORKS);
	print_philo_status(philo);
	modify_philo_state(philo, READY_TO_EAT);
}

void	return_forks(t_philo *philo)
{
	sem_post(philo->table->shared_locker->forks);
	sem_post(philo->table->shared_locker->forks);
}
