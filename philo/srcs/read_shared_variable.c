/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shared_variable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:24:04 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 20:35:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

int	read_dead_flag(t_philo *philo)
{
	int	dead_flag;

	pthread_mutex_lock(&(philo->table->locker->death));
	dead_flag = philo->table->dead_flag;
	pthread_mutex_unlock(&(philo->table->locker->death));
	return (dead_flag);
}
