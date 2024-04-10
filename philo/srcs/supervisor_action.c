/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:57:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/10 11:22:41 by bebrandt         ###   ########.fr       */
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
		if (table->meals_limit && read_dead_flag(table) == 0
			&& meals_limit_is_reached(table))
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

	i = 1;
	philo = table->first_philo;
	while (i <= table->nbr_philo)
	{
		if (read_meals_eaten(philo) < table->meals_limit)
			return (PHILOSOPHERS_ARE_STILL_HUNGRY);
		philo = philo->next;
		i++;
	}
	set_meals_limit_reached_to_one(table);
	return (ALL_PHILOSOPHER_EAT_ENOUGH);
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
		time_to_last_meal_eaten = ms_time_diff(read_last_meals_eaten(philo));
		if (time_to_last_meal_eaten > (size_t)(table->time->time_to_die))
		{
			philo_die(philo);
			return (ONE_PHILOSOPHER_IS_DEAD);
		}
		philo = philo->next;
		i++;
	}
	return (ALL_PHILOSOPHER_ARE_ALIVE);
}
