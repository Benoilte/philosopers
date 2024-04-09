/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:02:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 13:40:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

size_t	get_actual_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (ft_time(&now));
}

size_t	timestamp(size_t start)
{
	return (get_actual_time() - start);
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
	return (get_actual_time() - time);
}

void	ft_usleep(int ms)
{
	size_t	start_sleeping;

	start_sleeping = get_actual_time();
	while (timestamp(start_sleeping) < (size_t)ms)
		usleep(500);
}
