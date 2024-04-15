/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/15 16:07:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_shared_locker	*init_shared_locker(int nbr_philo)
{
	t_shared_locker	*shared_locker;

	shared_locker = (t_shared_locker *)malloc(sizeof(t_shared_locker));
	if (!shared_locker)
		return (NULL);
	shared_locker->print = sem_open(PRINT, O_CREAT, 0644, 1);
	if (init_semaphore_failed(shared_locker->print, PRINT))
		return (clean_shared_locker(shared_locker, 0, NULL));
	shared_locker->forks = sem_open(FORKS, O_CREAT, 0644, nbr_philo);
	if (init_semaphore_failed(shared_locker->forks, FORKS))
		return (clean_shared_locker(shared_locker, 1, NULL));
	shared_locker->death = sem_open(DEATH, O_CREAT, 0644, 0);
	if (init_semaphore_failed(shared_locker->death, DEATH))
		return (clean_shared_locker(shared_locker, 2, NULL));
	shared_locker->full = sem_open(FULL, O_CREAT, 0644, 0);
	if (init_semaphore_failed(shared_locker->full, FULL))
		return (clean_shared_locker(shared_locker, 3, NULL));
	shared_locker->stop = sem_open(STOP, O_CREAT, 0644, 0);
	if (init_semaphore_failed(shared_locker->stop, STOP))
		return (clean_shared_locker(shared_locker, 4, NULL));
	return (shared_locker);
}

t_philo_locker	*init_philo_locker(void)
{
	t_philo_locker	*philo_locker;

	philo_locker = (t_philo_locker *)malloc(sizeof(t_philo_locker));
	if (!philo_locker)
		return (NULL);
	philo_locker->philo_state_flag = sem_open(PHILO_STATE, O_CREAT, 0644, 1);
	if (init_semaphore_failed(philo_locker->philo_state_flag, PHILO_STATE))
		return (clean_philo_locker(philo_locker, 0, NULL));
	philo_locker->meals_flag = sem_open(MEALS, O_CREAT, 0644, 1);
	if (init_semaphore_failed(philo_locker->meals_flag, MEALS))
		return (clean_philo_locker(philo_locker, 1, NULL));
	return (philo_locker);
}

int	init_semaphore_failed(sem_t *sem, char *msg)
{
	if (sem == SEM_FAILED)
	{
		printf("Error: sem_open() FAILED to create %smsg\n", msg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
