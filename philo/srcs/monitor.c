/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:03:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/22 14:23:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*control_simulation(void *data)
{
	t_data	*shared;

	shared = (t_data *)data;
	while (*(shared->run_simulation))
	{
		if (meals_limit_is_reached(shared))
			*(shared->run_simulation) = 0;
		if (one_philo_is_die(shared))
			*(shared->run_simulation) = 0;
	}
	return (NULL);
}

int	meals_limit_is_reached(t_data *shared)
{
	int	i;

	if (shared->meals_limit == 0)
		return (0);
	i = 0;
	while (i < shared->n_philo)
	{
		if ((shared->meals)[i] < shared->meals_limit)
			return (0);
		i++;
	}

	return (1);
}

int	one_philo_is_die(t_data *shared)
{
	int				i;
	struct timeval	now;

	i = 0;
	while (i < shared->n_philo)
	{
		gettimeofday(&now, NULL);
		if ((ft_time(&now) - (shared->last_meal)[i]) > (size_t)(shared->time_to_die))
		{
			print_log(i, shared, "died");
			return (1);
		}
		i++;
	}
	return (0);
}
