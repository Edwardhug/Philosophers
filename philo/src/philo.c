/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:10:40 by lgabet            #+#    #+#             */
/*   Updated: 2024/02/05 16:23:31 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_main *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philo)
	{
		pthread_mutex_destroy(&var->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&var->global_mut);
	pthread_mutex_destroy(&var->write_mut);
	free(var->philo);
	free(var->thread);
	free(var->fork);
}

void	only_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("0 1 has taken a fork\n");
	usleep(philo->var->time_die * 1000);
	pthread_mutex_unlock(philo->right_fork);
	printf("%d 1 died\n", philo->var->time_die);
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
	return (0);
}
