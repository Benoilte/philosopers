/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/12 17:17:52 by bebrandt         ###   ########.fr       */
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
	t_philosopher_parent	*philosopher_parent;
	t_table					*table;
	t_philo					*philosopher;

	(void)philosopher_parent;
	(void)philosopher;
	table = init_table(argc, argv);
	if (!table)
		exit(EXIT_FAILURE);
	// philosopher_parent = init_philosopher_parent(table);
	// if (!philosopher_parent)
	// {
	// 	clean_table(table);
	// 	exit(EXIT_FAILURE);
	// }
	// philosopher = init_philosopher(table);
	// if (!philosopher)
	// {
	// 	clean_table(table);
	// 	clean_philosopher_parent(philosopher_parent);
	// 	exit(EXIT_FAILURE);
	// }
	printf("table is initialized\n");
	clean_table(table);
	// run_philosophers_dinner(table, philosopher_parent, philosopher);
}

void	run_philosophers_dinner(t_table *table,
			t_philosopher_parent *philosopher_parent, t_philo *philosopher)
{
	(void)table;
	(void)philosopher_parent;
	(void)philosopher;
	printf("let's run the philosophers dinner\n");
}

// void	wait_the_end_of_philosophers_dinner(t_table *table, int *status)
// {
// 	t_philo	*philo;
// 	int		i;

// 	i = 1;
// 	philo = table->first_philo;
// 	while (i <= table->nbr_philo)
// 	{
// 		if (pthread_join(philo->thread, NULL) != 0)
// 		{
// 			printf("Error: Failed to join philosopher %d thread\n", philo->id);
// 			*status = EXIT_FAILURE;
// 		}
// 		philo = philo->next;
// 		i++;
// 	}
// }
