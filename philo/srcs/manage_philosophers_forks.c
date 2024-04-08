/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philosophers_forks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:17:40 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 23:56:51 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));
	philo->state = TAKE_FORKS;
	select_log_msg(philo);
	pthread_mutex_lock(philo->right_fork);
	select_log_msg(philo);
	philo->state = READY_TO_EAT;
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork));
	pthread_mutex_unlock(philo->right_fork);
}
