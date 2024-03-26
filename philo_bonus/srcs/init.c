/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:51:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*init_philo(int argc, char **argv)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->count = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->meals_limit = ft_atoi(argv[5]);
	else
		philo->meals_limit = 0;
	philo->state = WANT_TO_EAT;
	philo->meals = 0;
	gettimeofday(&(philo->start), NULL);
	philo->last_meal = ft_time(&(philo->start));
	return (philo);
}

int	init_semaphore(t_philo *philo, sem_t *sem_forks, sem_t *sem_write)
{
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
	return (SEMAPHORES_SUCCESS);
}

void	init_pid_tab(pid_t *pid, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pid[i] = 0;
		i++;
	}
}
