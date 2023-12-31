/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:49 by lgabet            #+#    #+#             */
/*   Updated: 2023/12/06 21:19:53 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_actual_time(void)
{
	struct timeval	time;
	long long		ms_time;

	gettimeofday(&time, NULL);
	ms_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms_time);
}

int	init_struct(t_main *var, int ac, char **arg)
{
	var->finished = false;
	var->number_of_philo = ft_atoi(arg[1]);
	var->time_die = ft_atoi(arg[2]);
	var->time_eat = ft_atoi(arg[3]);
	var->time_sleep = ft_atoi(arg[4]);
	if (ac == 6)
		var->total_eat = ft_atoi(arg[5]);
	else
		var->total_eat = -1;
	var->thread = malloc(sizeof(pthread_t) * var->number_of_philo);
	if (!var->thread)
		return (1);
	var->philo = malloc(sizeof(t_philo) * var->number_of_philo);
	if (!var->philo)
		return (free(var->thread), 1);
	var->fork = malloc(sizeof(pthread_mutex_t) * var->number_of_philo);
	if (!var->fork)
		return (free(var->thread), free(var->philo), 1);
	return (0);
}
