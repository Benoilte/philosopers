/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:57:32 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 18:25:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_supervisor(t_table *table, int *status)
{
	if (pthread_create(&(table->supervisor), NULL, &monitoring, table) != 0)
	{
		printf("Error: Failed to create supervisor thread\n");
		table->dead_philo = 1;
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
	pthread_mutex_lock(&(table->locker->write));
	print_table(table);
	pthread_mutex_unlock(&(table->locker->write));
	return (NULL);
}
