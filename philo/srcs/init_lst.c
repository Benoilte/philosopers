/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 18:40:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nbr_philo = ft_atoi(argv[NUMBER_OF_PHILOSOPHER]);
	table->dead_philo = 0;
	table->meals_limit = 0;
	if (argc == 6)
		table->meals_limit = ft_atoi(argv[MEALS_LIMIT]);
	table->time = init_time(argv);
	if (!table->time)
	{
		free(table);
		return (NULL);
	}
	table->locker = init_locker();
	if (!table->locker)
	{
		free(table->time);
		free(table);
		return (NULL);
	}
	table->first_philo = NULL;
	return (table);
}

t_time	*init_time(char **argv)
{
	t_time	*time;

	time = (t_time *)malloc(sizeof(t_time));
	if (!time)
		return (NULL);
	time->time_to_die = ft_atoi(argv[TIME_TO_DIE]);
	time->time_to_eat = ft_atoi(argv[TIME_TO_EAT]);
	time->time_to_sleep = ft_atoi(argv[TIME_TO_SLEEP]);
	time->start_time = 0;
	return (time);
}

t_locker	*init_locker(void)
{
	t_locker	*locker;

	locker = (t_locker *)malloc(sizeof(t_locker));
	if (!locker)
		return (NULL);
	if (locker_mutex_init(locker, &(locker->write), "write", 0))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->meals_limit), "meals_limit", 1))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->meals_limit_reached),
			"meals_limit_reached", 2))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->last_meal), "last_meal", 3))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->death), "death", 4))
		return (NULL);
	return (locker);
}

int	locker_mutex_init(t_locker *locker, pthread_mutex_t *mutex, char *msg,
					int nbr_of_locker)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		printf("Error: Failed to init %s mutex\n", msg);
		clean_locker(locker, nbr_of_locker, NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
