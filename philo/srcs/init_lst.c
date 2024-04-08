/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 15:08:03 by bebrandt         ###   ########.fr       */
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
		free(table);
		free(time);
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
	if (pthread_mutex_init(&(locker->write), NULL))
	{
		printf("Error: Failed to init write mutex\n");
		clean_locker(locker, 0);
		return (NULL);
	}
	if (pthread_mutex_init(&(locker->meal), NULL))
	{
		printf("Error: Failed to init meal mutex\n");
		clean_locker(locker, 1);
		return (NULL);
	}
	if (pthread_mutex_init(&(locker->last_meal), NULL))
	{
		printf("Error: Failed to init last_meal mutex");
		clean_locker(locker, 2);
		return (NULL);
	}
	return (locker);
}

t_philo	*init_all_philosophers(t_table *table)
{
	t_philo	*philo;
	t_philo	*philosophers;
	int		i;

	i = 1;
	philosophers = NULL;
	while (i <= table->nbr_philo)
	{
		philo = init_one_philosophers(table, i);
		if (!philo)
		{
			clean_all_philosophers(&philosophers);
			return (NULL);
		}
		add_philo_to_philosophers(philo, &philosophers);
		i++;
	}
	return (philosophers);
}

t_philo	*init_one_philosophers(t_table *table, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (pthread_mutex_init(&(philo->left_fork), NULL))
	{
		printf("Error: Failed to init left_fork mutex");
		printf(" of philo %d\n", id);
		free(philo);
		return (NULL);
	}
	philo->id = id;
	philo->state = id % 2;
	philo->meals_eaten = 0;
	philo->last_meal_eaten = 0;
	philo->right_fork = NULL;
	philo->table = table;
	philo->time = table->time;
	philo->prev = NULL;
	philo->next = NULL;
	return (philo);
}
