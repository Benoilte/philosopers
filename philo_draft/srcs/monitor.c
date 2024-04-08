/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:03:01 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/05 13:58:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*control_simulation(void *data)
{
	t_data	*shared;

	shared = (t_data *)data;
	ft_usleep(shared->time_to_die / 2);
	while (*(shared->run_simulation))
	{
		if (meals_limit_is_reached(shared))
			*(shared->run_simulation) = 0;
		is_one_philosopher_starving(shared);
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

void	is_one_philosopher_starving(t_data *shared)
{
	int		i;
	size_t	diff;

	i = 0;
	while (i < shared->n_philo)
	{
		pthread_mutex_lock(&(shared->m_last_meal));
		diff = ft_get_diff(shared->last_meal[i]);
		pthread_mutex_unlock(&(shared->m_last_meal));
		if (diff > (size_t)(shared->time_to_die))
		{
			printf("%zu diff : %zu\n", timestamp(&(shared->start)),diff);
			print_log(i, shared, "died", 1);
			*(shared->run_simulation) = 0;
			return ;
		}
		i++;
	}
}
