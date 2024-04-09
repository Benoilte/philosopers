/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:30:28 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/26 18:06:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_routine(t_philo *philo)
{
	sem_t			*sem_forks;
	sem_t			*sem_write;

	sem_forks = sem_open(LOCK_FORKS, O_CREAT, 0600, philo->count / 2);
	if (sem_forks == SEM_FAILED)
	{
		printf("Error: sem_open() FAILED to create sem_forks\n");
		return (SEMAPHORES_FAILURE);
	}
	sem_write = sem_open(LOCK_WRITE, O_CREAT, 0600, 0);
	if (sem_write == SEM_FAILED)
	{
		printf("Error: sem_open() FAILED to create sem_write\n");
		return (SEMAPHORES_FAILURE);
	}
	print_log(philo, "start its routine", sem_write);
	exit(EXIT_SUCCESS);
}
