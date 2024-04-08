/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:32:48 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/05 13:57:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	other_must_eat_first(t_philo *philo)
{
	int		i;
	size_t	*last_meal;

	last_meal = philo->shared->last_meal;
	i = 0;
	while (i < philo->shared->n_philo)
	{
		if (last_meal[philo->id] > last_meal[i])
			return (1);
		i++;
	}
	return (0);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->shared->m_forks + philo->left_fork_id);
	print_log(philo->id, philo->shared, "has taken a left fork", 0);
	pthread_mutex_lock(philo->shared->m_forks + philo->right_fork_id);
	print_log(philo->id, philo->shared, "has taken a right fork", 0);
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->shared->m_forks + philo->left_fork_id);
	pthread_mutex_unlock(philo->shared->m_forks + philo->right_fork_id);
}
