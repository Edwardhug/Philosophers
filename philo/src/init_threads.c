/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:07:41 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/27 13:34:55 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *philo_loop()
{
	printf("new thread\n");
	return (NULL);
}

void create_thread(t_main *var, int i)
{
	pthread_create(&var->thread[i], NULL, &philo_loop, NULL);
}

void init_threads(t_main *var)
{
	int	i;

	i = 0;
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