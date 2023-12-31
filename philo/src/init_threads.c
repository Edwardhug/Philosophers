/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:07:41 by lgabet            #+#    #+#             */
/*   Updated: 2023/12/06 21:28:45 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_fork(t_main *var)
{
	int	i;

	i = 0;
	while (i < var->number_of_philo)
	{
		if (i == 0)
			var->philo[i].left_fork = &var->fork[var->number_of_philo - 1];
		else
			var->philo[i].left_fork = &var->fork[i - 1];
		var->philo[i].right_fork = &var->fork[i];
		i++;
	}
}

void	create_mutex(t_main *var)
{
	int	i;

	i = 0;
	pthread_mutex_init(&var->write_mut, NULL);
	pthread_mutex_init(&var->global_mut, NULL);
	while (i < var->number_of_philo)
	{
		var->philo[i].number = i + 1;
		var->philo[i].var = var;
		var->philo[i].number_of_meal = 0;
		var->philo[i].time_start = get_actual_time();
		var->philo[i].time_last_meal = get_actual_time();
		pthread_mutex_init(&var->fork[i], NULL);
		i++;
	}
	init_fork(var);
}

int	init_threads(t_main *var)
{
	int	i;

	i = 0;
	create_mutex(var);
	while (i < var->number_of_philo)
	{
		if (pthread_create(&var->thread[i], NULL,
				&routine_philo, (void *)&var->philo[i]) != 0)
			return (printf("Error pthread_create\n"), 0);
		i++;
	}
	i = 0;
	check_dead_or_finished(var);
	pthread_mutex_lock(&var->global_mut);
	var->finished = true;
	pthread_mutex_unlock(&var->global_mut);
	while (i < var->number_of_philo)
	{
		if (pthread_join(var->thread[i], NULL) != 0)
			return (printf("Error pthread_join\n"), 0);
		i++;
	}
	return (1);
}
