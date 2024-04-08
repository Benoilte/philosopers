/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shared_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:20:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 20:29:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	modify_dead_flag(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->locker->death));
	philo->table->dead_flag = 1;
	pthread_mutex_unlock(&(philo->table->locker->death));
}
