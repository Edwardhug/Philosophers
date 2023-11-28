/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:07:41 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 13:56:33 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void create_thread(t_main *var, int i)
{
	var->philo[i].number = i;
	var->philo[i].var = var;
	var->philo[i].alive = true;
	pthread_mutex_init(&var->philo->right_fork, NULL);
	pthread_create(&var->thread[i], NULL, &routine_philo, (void *)&var->philo[i]);
}

void init_threads(t_main *var)
{
	int	i;

	i = 0;
	pthread_mutex_init(&var->write_mut, NULL);
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