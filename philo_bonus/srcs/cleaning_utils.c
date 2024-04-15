/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:52:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 10:02:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*clean_shared_locker(t_shared_locker *shared_locker, int nbr_locker)
{
	if (shared_locker)
	{
		if (nbr_locker >= 1)
			sem_close(shared_locker->print);
		if (nbr_locker >= 2)
			sem_close(shared_locker->forks);
		if (nbr_locker >= 3)
			sem_close(shared_locker->death);
		if (nbr_locker >= 4)
			sem_close(shared_locker->full);
		if (nbr_locker >= 5)
			sem_close(shared_locker->stop);
		unlink_semaphore();
		free(shared_locker);
	}
	return (NULL);
}

void	*clean_philo_locker(t_philo_locker *philo_locker, int nbr_locker)
{
	if (philo_locker)
	{
		if (nbr_locker >= 1)
			sem_close(philo_locker->dinner_state_flag);
		if (nbr_locker >= 2)
			sem_close(philo_locker->meals_flag);
		unlink_semaphore();
		free(philo_locker);
	}
	return (NULL);
}

void	unlink_semaphore(void)
{
	sem_unlink(PRINT);
	sem_unlink(FORKS);
	sem_unlink(DEATH);
	sem_unlink(FULL);
	sem_unlink(STOP);
}
