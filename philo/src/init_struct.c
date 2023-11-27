/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:16:49 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/27 13:36:23 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int get_actual_time()
{
	struct timeval	time;
	long long		ms_time;

	gettimeofday(&time, NULL);
	ms_time = (time.tv_sec / 60 * 1000) + time.tv_usec;
	return (ms_time);
}

int	init_struct(t_main *var, int ac, char **arg)
{
	var->number_of_philo = ft_atoi(arg[1]);
	var->time_die = ft_atoi(arg[2]);
	var->time_eat = ft_atoi(arg[3]);
	var->time_sleep = ft_atoi(arg[4]);
	if (ac ==  6)
		var->total_eat = ft_atoi(arg[5]);
	else
		var->total_eat = -1;
	var->thread = malloc(sizeof(pthread_t) * var->number_of_philo);
	if (!var->thread)
		return (1);
	var->philo = malloc(sizeof(t_philo) * var->number_of_philo);
	if (!var->philo)
		return (free(var->thread), 1);
	var->time_start = get_actual_time();
	return (0);
}
