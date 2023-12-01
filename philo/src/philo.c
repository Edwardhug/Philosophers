/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:10:40 by lgabet            #+#    #+#             */
/*   Updated: 2023/12/01 14:31:06 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void free_all(t_main *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philo)
	{
		pthread_mutex_destroy(&var->philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&var->global_mut);
	pthread_mutex_destroy(&var->write_mut);
	free(var->philo);
	free(var->thread);
}

int	main(int ac, char **av)
{
	t_main	var;

	if ((ac != 5 && ac != 6) || is_no_numeric(av, ac))
		return (printf("Error with parameters\n"), 1);
	if (init_struct(&var, ac, av))
		return (printf("Malloc error during init\n"), 1);
	init_threads(&var);
	free_all(&var);
	return(0);
}