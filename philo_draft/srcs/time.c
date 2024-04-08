/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:36:49 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/03 22:37:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

size_t	ft_get_diff(size_t time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (ft_time(&now) - time);
}

void	ft_usleep(int ms)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	while (timestamp(&now) < (size_t)ms)
		usleep(500);
}
