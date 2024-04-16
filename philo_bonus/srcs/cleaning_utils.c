/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:52:21 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 09:59:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*clean_shared_locker(t_shared_locker *shared_locker, int nbr_locker,
			int *status)
{
	if (shared_locker)
	{
		if (nbr_locker >= 1)
			close_semaphore(shared_locker->print, PRINT, status);
		if (nbr_locker >= 2)
			close_semaphore(shared_locker->forks, FORKS, status);
		if (nbr_locker >= 3)
			close_semaphore(shared_locker->death, DEATH, status);
		if (nbr_locker >= 4)
			close_semaphore(shared_locker->full, FULL, status);
		if (nbr_locker >= 5)
			close_semaphore(shared_locker->stop, STOP, status);
		unlink_semaphore();
		free(shared_locker);
	}
	return (NULL);
}

void	*clean_philo_locker(t_philo_locker *philo_locker, int nbr_locker,
			int *status)
{
	if (philo_locker)
	{
		if (nbr_locker >= 1)
			close_semaphore(philo_locker->run_condition, RUN_CONDITION,
				status);
		if (nbr_locker >= 2)
			close_semaphore(philo_locker->state, PHILO_STATE, status);
		if (nbr_locker >= 3)
			close_semaphore(philo_locker->meals, MEALS, status);
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
	sem_unlink(RUN_CONDITION);
	sem_unlink(PHILO_STATE);
	sem_unlink(MEALS);
	sem_unlink(READ_AND_UPDATE);
}

void	close_semaphore(sem_t *sem, char *msg, int *status)
{
	if (sem_close(sem))
	{
		printf("Error: sem_close() FAILED to close %smsg\n", msg);
		if (status)
			*status = EXIT_FAILURE;
	}
}
