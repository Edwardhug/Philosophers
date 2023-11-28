/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:07:41 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 15:30:15 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_thread(t_main *var, int i)
{
	pthread_create(&var->thread[i], NULL, &routine_philo, (void *)&var->philo[i]);
}

void	create_mutex(t_main *var)
{
	int	i;

	i = 0;
	pthread_mutex_init(&var->write_mut, NULL);
	while (i < var->number_of_philo)
	{
		var->philo[i].number = i + 1;
		var->philo[i].var = var;
		var->philo[i].alive = true;
		var->philo[i].number_of_meal = 0;
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
		create_thread(var, i);
		i++;
	}
	i = 0;
	while (i < var->number_of_philo)
	{
		pthread_join(var->thread[i], NULL);
		i++;
	}
}