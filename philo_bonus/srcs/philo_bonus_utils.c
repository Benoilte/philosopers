/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:42:58 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/26 17:54:26 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_log(t_philo *philo, char *msg, sem_t *sem_write)
{
	if (sem_wait(sem_write) < 0)
		printf("sem_wait() FAILED\n");
	sleep(1);
	printf("%zu %d %s\n", timestamp(&(philo->start)), philo->id + 1, msg);
	if (sem_post(sem_write) < 0)
		printf("sem_post() FAILED\n");
}

size_t	timestamp(struct timeval *start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (ft_time(&now) - ft_time(start));
}

size_t	ft_time(struct timeval *time)
{
	size_t	sec;
	size_t	usec;

	sec = time->tv_sec * 1000;
	usec = time->tv_usec / 1000;
	return (sec + usec);
}

void	clean(t_philo *philo)
{
	if (philo)
	{
		free(philo);
	}
}
