/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:05:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 11:52:46 by bebrandt         ###   ########.fr       */
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
	table->dead_flag = 0;
	table->meals_limit = 0;
	table->meals_limit_reached = 0;
	if (argc == 6)
		table->meals_limit = ft_atoi(argv[MEALS_LIMIT]);
	table->first_philo = NULL;
	table->time = init_time(argv);
	if (!table->time)
	{
		free(table);
		return (NULL);
	}
	table->locker = init_locker();
	if (!table->locker)
	{
		clean_table(table, NULL);
		return (NULL);
	}
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
	if (locker_mutex_init(locker, &(locker->print), "print", 0))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->meals_limit_reached),
			"meals_limit_reached", 1))
		return (NULL);
	if (locker_mutex_init(locker, &(locker->death), "death", 2))
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
