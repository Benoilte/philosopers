/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/09 15:47:20 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

sem_t *sem_forks;

void	*routine(void* args)
{
	sem_wait(sem_forks);
	printf("(%d) HELLO WORLD\n", *(int*)args);
	ft_usleep(500);
	sem_post(sem_forks);
	free(args);
	return (NULL);
}

int	main(int argc, char *argv[]) 
{
	(void)argv;
	(void)argc;
	pthread_t th[THREAD_NUM];
	sem_forks = sem_open(LOCK_FORKS, O_CREAT, 0644, 2);
	if (sem_forks == SEM_FAILED)
	{
		printf("Error: sem_open() FAILED to create sem_forks\n");
		return (EXIT_FAILURE);
	}
	int i;
	for (i = 0; i < THREAD_NUM; i++) 
	{
	    int* a = malloc(sizeof(int));
	    *a = i;
	    if (pthread_create(&th[i], NULL, &routine, a) != 0) {
	        perror("Failed to create thread");
	    }
	}	
	for (i = 0; i < THREAD_NUM; i++) {
	    if (pthread_join(th[i], NULL) != 0) {
	        perror("Failed to join thread");
	    }
	}
	sem_close(sem_forks);
	sem_unlink(LOCK_FORKS);
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	if (arg_is_not_valid(argc, argv))
// 		return (EXIT_FAILURE);
// 	return (prep_philosophers_dinner(argc, argv));
// }

// int	prep_philosophers_dinner(int argc, char **argv)
// {
// 	(void)argv;
// 	(void)argc;
// 	printf("let's prep the philosophers dinner\n");
// 	return (EXIT_SUCCESS);
// }

// void	run_philosophers_dinner(t_table *table, int *status)
// {
// 	if (table->nbr_philo == 1)
// 		start_routine_alone(table, status);
// 	else
// 		start_routine_together(table, status);
// 	start_supervisor(table, status);
// 	wait_the_end_of_philosophers_dinner(table, status);
// 	wait_the_end_of_supervisor(table, status);
// 	clean_table(table, status);
// }

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
