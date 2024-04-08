/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:57:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 01:13:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_supervisor(t_table *table, int *status)
{
	if (pthread_create(&(table->supervisor), NULL, &monitoring, table) != 0)
	{
		printf("Error: Failed to create supervisor thread\n");
		table->dead_flag = 1;
		*status = EXIT_FAILURE;
	}
}

void	wait_the_end_of_supervisor(t_table *table, int *status)
{
	if (pthread_join(table->supervisor, NULL) != 0)
	{
		printf("Error: Failed to join supervisor thread\n");
		*status = EXIT_FAILURE;
	}
}

void	*monitoring(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (dinner_is_not_finished(table->first_philo))
	{
		if (meals_limit_is_reached(table))
			break ;
		if (one_philosopher_starve(table))
			break ;
	}
	return (NULL);
}

int	meals_limit_is_reached(t_table *table)
{
	t_philo	*philo;
	int		i;

	if (table->meals_limit == 0)
		return (0);
	i = 1;
	philo = table->first_philo;
	while (i <= table->nbr_philo)
	{
		if (read_meals_eaten(philo) < table->meals_limit)
			return (0);
		philo = philo->next;
		i++;
	}
	modify_meals_limit_reached(table);
	return (1);
}

int	one_philosopher_starve(t_table *table)
{
	t_philo	*philo;
	size_t	time_to_last_meal_eaten;
	int		i;

	i = 1;
	philo = table->first_philo;
	while (i <= table->nbr_philo)
	{
		time_to_last_meal_eaten = ft_get_diff(read_last_meals_eaten(philo));
		if (time_to_last_meal_eaten > (size_t)(table->time->time_to_die))
		{
			philo_die(philo);
			modify_dead_flag(table);
			return (1);
		}
		philo = philo->next;
		i++;
	}
	return (0);
}
