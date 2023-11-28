/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 14:21:05 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d has taken a fork\n", (get_actual_time() - philo->time_start), philo->number);
	pthread_mutex_unlock(&philo->var->write_mut);
	if (philo->number != philo->var->number_of_philo)
		pthread_mutex_lock(&philo->var->philo[philo->number + 1].right_fork);
	else
		pthread_mutex_lock(&philo->var->philo[0].right_fork);
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d has taken a fork\n", (get_actual_time() - philo->time_start), philo->number);
	pthread_mutex_unlock(&philo->var->write_mut);
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d is eating\n", (get_actual_time() - philo->time_start), philo->number);
	pthread_mutex_unlock(&philo->var->write_mut);
	usleep(philo->var->time_eat);
	pthread_mutex_unlock(&philo->right_fork);
	if (philo->number != philo->var->number_of_philo)
		pthread_mutex_unlock(&philo->var->philo[philo->number + 1].right_fork);
	else
		pthread_mutex_unlock(&philo->var->philo[0].right_fork);
	philo->number_of_meal++;
}

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	philo->time_start = get_actual_time();
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d is thinking\n", (get_actual_time() - philo->time_start), philo->number);
	pthread_mutex_unlock(&philo->var->write_mut);
	while (are_all_alive(arg) && philo->number_of_meal != philo->var->total_eat)
	{
		eating_routine(philo);
	}
	return (0);
}