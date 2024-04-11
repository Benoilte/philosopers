/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:02:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/11 13:27:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	ms_actual_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (ms_time(&now));
}

size_t	ms_timestamp(size_t start)
{
	return (ms_actual_time() - start);
}

size_t	ms_time(struct timeval *time)
{
	size_t	sec;
	size_t	usec;

	sec = time->tv_sec * 1000;
	usec = time->tv_usec / 1000;
	return (sec + usec);
}

size_t	ms_time_diff(size_t time)
{
	return (ms_actual_time() - time);
}

void	ms_sleep(int ms)
{
	size_t	start_sleeping;

	start_sleeping = ms_actual_time();
	while (ms_timestamp(start_sleeping) < (size_t)ms)
		usleep(500);
}
