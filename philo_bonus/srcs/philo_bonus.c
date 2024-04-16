/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/16 12:03:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	if (arg_is_not_valid(argc, argv))
		return (EXIT_FAILURE);
	prep_philosophers_dinner(argc, argv);
	return (EXIT_SUCCESS);
}

void	prep_philosophers_dinner(int argc, char **argv)
{
	t_table		*table;
	t_parent	*parent;
	t_philo		*philosopher;

	table = init_table(argc, argv);
	if (!table)
		exit(EXIT_FAILURE);
	parent = init_parent(table);
	if (!parent)
	{
		clean_table(table, NULL);
		exit(EXIT_FAILURE);
	}
	philosopher = init_philosopher(table);
	if (!philosopher)
	{
		clean_table(table, NULL);
		clean_parent(parent, NULL);
		exit(EXIT_FAILURE);
	}
	run_philosophers_dinner(table, parent, philosopher);
}

void	run_philosophers_dinner(t_table *table, t_parent *parent,
			t_philo *philosopher)
{
	int	status;

	status = EXIT_SUCCESS;
	create_philosopher(table, parent, philosopher);
	if (parent->philosopher_pid[philosopher->id - 1] == -1)
		set_stop_simulation(parent);
	else if (parent->philosopher_pid[philosopher->id - 1] == 0)
		start_philosopher_routine(table, parent, philosopher, &status);
	else
		start_parent_monitoring(parent, &status);
	wait_the_end_of_philosophers_dinner(parent);
	clean_all(table, parent, philosopher, &status);
	exit(status);
}

void	create_philosopher(t_table *table, t_parent *parent,
			t_philo *philosopher)
{
	int	i;

	i = 0;
	philosopher->time->start_time = ms_actual_time();
	philosopher->last_meal_eaten = ms_actual_time();
	while (i < table->nbr_philo)
	{
		parent->philosopher_pid[i] = fork();
		if (parent->philosopher_pid[i] == 0)
		{
			philosopher->id = i + 1;
			philosopher->state = (i + 1) % 2;
			break ;
		}
		i++;
	}
}

void	wait_the_end_of_philosophers_dinner(t_parent *parent)
{
	int		i;

	i = 0;
	while (i < parent->table->nbr_philo)
	{
		if (parent->philosopher_pid[i] != 0)
			waitpid(parent->philosopher_pid[i], NULL, 0);
		i++;
	}
}
