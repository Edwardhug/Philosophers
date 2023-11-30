/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/29 13:42:01 by lgabet           ###   ########.fr       */
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

void	uneven_eating_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	print_info(philo, "has taken a fork");
	if (philo->number != philo->var->number_of_philo)
		pthread_mutex_lock(&philo->var->philo[philo->number].right_fork);
	else
		pthread_mutex_lock(&philo->var->philo[0].right_fork);
	print_info(philo, "has taken a fork");
	print_info(philo, "is eating");
	pthread_mutex_lock(&philo->var->global_mut);
	philo->time_last_meal = get_actual_time();
	pthread_mutex_unlock(&philo->var->global_mut);
	usleep(philo->var->time_eat * 1000);
	pthread_mutex_unlock(&philo->right_fork);
	if (philo->number != philo->var->number_of_philo)
		pthread_mutex_unlock(&philo->var->philo[philo->number].right_fork);
	else
		pthread_mutex_unlock(&philo->var->philo[0].right_fork);
	pthread_mutex_lock(&philo->var->global_mut);
	philo->number_of_meal++;
	pthread_mutex_unlock(&philo->var->global_mut);
}

// void	even_eating_routine(t_philo *philo)
// {
// 	if (philo->number != philo->var->number_of_philo - 1)
// 		pthread_mutex_lock(&philo->var->philo[philo->number + 1].right_fork);
// 	else
// 		pthread_mutex_lock(&philo->var->philo[0].right_fork);
// 	print_info(philo, "has taken a fork");
// 	pthread_mutex_lock(&philo->right_fork);
// 	print_info(philo, "has taken a fork");
// 	print_info(philo, "is eating");
// 	usleep(philo->var->time_eat * 1000);
// 	if (philo->number != philo->var->number_of_philo - 1)
// 		pthread_mutex_unlock(&philo->var->philo[philo->number + 1].right_fork);
// 	else
// 		pthread_mutex_unlock(&philo->var->philo[0].right_fork);
// 	pthread_mutex_unlock(&philo->right_fork);
// 	pthread_mutex_lock(&philo->var->global_mut);
// 	philo->number_of_meal++;
// 	philo->time_last_meal = get_actual_time();
// 	pthread_mutex_unlock(&philo->var->global_mut);
// }

void	sleep_routine(t_philo *philo)
{
	print_info(philo, "is sleeping");
	usleep(philo->var->time_sleep * 1000);
}

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->var->global_mut);
	philo->time_start = get_actual_time();
	philo->time_last_meal = philo->time_start;
	pthread_mutex_unlock(&philo->var->global_mut);
	print_info(philo, "is thinking");
	while (philo_must_continue(philo))
	{
		// if (philo->var->number_of_philo % 2 != 0)
			uneven_eating_routine(philo);
		// else
		// 	even_eating_routine(philo);
		sleep_routine(philo);
		print_info(philo, "is thinking");
	}
	return (0);
}
