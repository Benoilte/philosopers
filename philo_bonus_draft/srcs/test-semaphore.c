/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:30:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/10 21:31:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t *sem_death;
sem_t *sem_eat_enough;

void	routine(int id)
{
	int n;

	n = 0;
	while (n != 5)
	{
		n++;
		sleep(id);
		printf("philo %d sleep %d times\n", id, n);
	}
	sem_post(sem_death);
	while (n)
	{
		n--;
		sleep(id);
		printf("philo %d eat %d times\n", id, n);
	}
	sem_post(sem_eat_enough);

}

void	*check_death(void *arg)
{
	int	philo;
	int n;

	philo = *(int *)arg;
	n = philo;
	while (philo)
	{
		sem_wait(sem_death);
		philo--;
		printf("%d philo died\n", n - philo);
	}
	while (n)
	{
		sem_post(sem_death);
		n--;
	}
	return (NULL);
}

void	*check_eating(void *arg)
{
	int	n;
	int	philo;

	philo = *(int *)arg;
	n = 1;
	while (n <= philo)
	{
		sem_wait(sem_eat_enough);
		n++;
		printf("%d philo eat enough\n", n);
	}
	while (philo)
	{
		sem_post(sem_eat_enough);
		philo--;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	philo;
	int	i;
	int id;
	pid_t pid;
	pthread_t	th_1;
	pthread_t	th_2;

	if (argc != 2)
		return (EXIT_FAILURE);
	philo = ft_atoi(argv[1]);
	sem_unlink(DEATH);
	sem_unlink(EAT_ENOUGH);
	sem_death = sem_open(DEATH, O_CREAT, 0644, philo);
	sem_eat_enough = sem_open(EAT_ENOUGH, O_CREAT, 0644, philo);
	id = 1;
	i = 0;
	while (i < philo)
	{
		pid = fork();
		if (pid)
		{
			id += 1;
			i++;
		}
		else
			break ;
	}
	if (pid == 0)
	{
		sem_wait(sem_death);
		sem_wait(sem_eat_enough);
		routine(id);
	}
	else
	{
		sleep(1);
		pthread_create(&th_1, NULL, &check_death, &philo);
		pthread_create(&th_2, NULL, &check_eating, &philo);
		pthread_join(th_1, NULL);
		pthread_join(th_2, NULL);
	}
	sem_close(sem_death);
	return (0);
}
