/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 08:47:13 by bebrandt          #+#    #+#             */
/*   Updated: 2024/04/08 09:04:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_argument_definition(int arg)
{
	if (arg == NUMBER_OF_PHILOSOPHER)
		printf("Number of philosopher");
	else if (arg == TIME_TO_DIE)
		printf("Time to die");
	else if (arg == TIME_TO_EAT)
		printf("Time to eat");
	else if (arg == TIME_TO_SLEEP)
		printf("Time to sleep");
	else if (arg == MEALS_LIMIT)
		printf("Number of times each philosopher must eat");
}
