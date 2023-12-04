/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by lgabet            #+#    #+#             */
/*   Updated: 2023/12/04 16:48:03 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_info(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->var->global_mut);
	if (philo->var->finished == false)
	{
		pthread_mutex_lock(&philo->var->write_mut);
		printf("%lld %d %s\n", (get_actual_time() - philo->time_start), philo->number, str);
		pthread_mutex_unlock(&philo->var->write_mut);	
	}
	pthread_mutex_unlock(&philo->var->global_mut);
}

void ft_usleep(long long to_wait)
{
	long long time;

	time = get_actual_time();
	while ((get_actual_time()) - time < to_wait)
		usleep(to_wait / 10);
}

void uneven_eating_routine(t_philo *philo)
{
	if (philo->number % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_info(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_info(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_info(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_info(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->var->global_mut);
	philo->time_last_meal = get_actual_time();
	philo->number_of_meal++;
	pthread_mutex_unlock(&philo->var->global_mut);
	print_info(philo, "is eating");
	ft_usleep(philo->var->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_routine(t_philo *philo)
{
	print_info(philo, "is sleeping");
	ft_usleep(philo->var->time_eat);
}

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->var->global_mut);
	philo->time_start = get_actual_time();
	philo->time_last_meal = philo->time_start;
	pthread_mutex_unlock(&philo->var->global_mut);
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d %s\n", (get_actual_time() - philo->time_start), philo->number, "is thinking");
	pthread_mutex_unlock(&philo->var->write_mut);
	while (philo_must_continue(philo))
	{
		uneven_eating_routine(philo);
		sleep_routine(philo);
		print_info(philo, "is thinking");
	}
	return (0);
}
