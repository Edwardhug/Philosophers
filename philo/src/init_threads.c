/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:07:41 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 19:35:41 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
		var->philo[i].time_last_meal = get_actual_time();
		pthread_mutex_init(&var->philo->right_fork, NULL);
		i++;
	}
}

void init_threads(t_main *var)
{
	int	i;

	i = 0;
	create_mutex(var);
	while (i < var->number_of_philo)
	{
		pthread_create(&var->thread[i], NULL, &routine_philo, (void *)&var->philo[i]);
		i++;
	}
	i = 0;
	check_dead_or_finished(var);
	pthread_mutex_lock(&var->global_mut);
	var->finished = true;
	pthread_mutex_unlock(&var->global_mut);
	while (i < var->number_of_philo)
	{
		pthread_join(var->thread[i], NULL);
		i++;
	}
}
