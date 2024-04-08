/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:34:15 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/07 19:17:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (arg_is_not_valid(argc, argv))
		return (ERROR);
	return (start_philosophers_dinner(argc, argv));
}

int	start_philosophers_dinner(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("let's start the philosopher dinner");
	return (0);
}
