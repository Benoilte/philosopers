/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:31:10 by bebrandt          #+#    #+#             */
/*   Updated: 2024/03/19 15:54:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philosophers	*ph;
	int				i;
	int				*a;

	(void)argc;
	ph = (t_philosophers *)malloc(sizeof(t_philosophers));
	ph->size = ft_atoi(argv[1]);
	printf("number of philosopher: %d\n", ph->size);
	ph->philos = (pthread_t *)malloc(sizeof(pthread_t) * (ph->size));
	if (!ph->philos)
		return (1);
	i = 0;
	while (i < ph->size)
	{
		a = (int *)malloc(sizeof(int));
		*a = i + 1;
		pthread_create(ph->philos + i, NULL, &routine, a);
		i++;
	}
	i = 0;
	while (i < ph->size)
	{
		pthread_join((ph->philos)[i], NULL);
		i++;
	}
	free(ph->philos);
	return (0);
}

void	*routine(void *num)
{
	printf("Hello, I'm the %d philosoper\n", *((int *)num));
	// printf("Hello, I'm philo number %d\n", ft_philo_number(ph->philos, ));
	return (NULL);
}

int	ft_philo_number(pthread_t *philos, pthread_t philo, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((philos + i) == &philo)
			return (i + 1);
		i++;
	}
	return (0);
}
