/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:00 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 09:30:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
			clean_all_philosophers(&philosophers, NULL);
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
	if (philo_mutex_init(philo, id))
		return (NULL);
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

int	philo_mutex_init(t_philo *philo, int id)
{
	if (pthread_mutex_init(&(philo->left_fork), NULL))
	{
		print_error_to_init_philo_mutex("left_fork", id);
		free(philo);
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&(philo->meals), NULL))
	{
		print_error_to_init_philo_mutex("meals", id);
		philo_mutex_destroy(&(philo->left_fork), id, "left_fork", NULL);
		free(philo);
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&(philo->lock_state), NULL))
	{
		print_error_to_init_philo_mutex("lock_state", id);
		philo_mutex_destroy(&(philo->left_fork), id, "left_fork", NULL);
		philo_mutex_destroy(&(philo->meals), id, "meals", NULL);
		free(philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	print_error_to_init_philo_mutex(char *msg, int id)
{
	printf("Error: Failed to init %s mutex of philo %d\n", msg, id);
}
