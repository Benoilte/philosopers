/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philosophers_forks.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:17:40 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 11:22:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));
	modify_philo_state(philo, TAKE_FORKS);
	print_philo_status(philo);
	pthread_mutex_lock(philo->right_fork);
	modify_philo_state(philo, TAKE_FORKS);
	print_philo_status(philo);
	modify_philo_state(philo, READY_TO_EAT);
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork));
	pthread_mutex_unlock(philo->right_fork);
}
