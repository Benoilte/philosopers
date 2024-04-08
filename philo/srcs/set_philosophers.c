/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:59:43 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 19:21:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_philo_to_philosophers(t_philo *philo, t_philo **philosophers)
{
	t_philo	*last_philo;

	if (!*philosophers)
	{
		*philosophers = philo;
		return ;
	}
	last_philo = *philosophers;
	while (last_philo->next && last_philo->id < last_philo->table->nbr_philo)
		last_philo = last_philo->next;
	last_philo->next = philo;
	last_philo->right_fork = &(philo->left_fork);
	philo->prev = last_philo;
	if (philo->id == last_philo->table->nbr_philo)
	{
		philo->next = *philosophers;
		philo->right_fork = &((*philosophers)->left_fork);
		(*philosophers)->prev = philo;
	}
}

void	init_philosophers_dinner_start(t_table *table)
{
	size_t	starting_time;
	t_philo	*philo;
	int		i;

	i = 1;
	philo = table->first_philo;
	starting_time = get_actual_time();
	philo->time->start_time = starting_time;
	while (i <= table->nbr_philo)
	{
		philo->last_meal_eaten = starting_time;
		philo = philo->next;
		i++;
	}
}
