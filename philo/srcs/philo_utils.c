/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:01:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/20 21:38:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(pthread_t *th, t_shared_var *shared)
{
	free(th);
	free(shared->all_alive);
	free(shared->forks);
	free(shared->meals);
	free(shared);
	pthread_mutex_destroy(&(shared->mutex));
}

void	*routine(void *philo)
{
	int i;

	i = 0;
	while (((t_philo *)philo)->shared->all_alive && i < 100)
	{
		ft_eat((t_philo *)philo);
		ft_sleep((t_philo *)philo);
		ft_think((t_philo *)philo);
		i++;
	}
	free(philo);
	return (NULL);
}
