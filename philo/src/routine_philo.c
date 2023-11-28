/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgabet <lgabet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:12 by lgabet            #+#    #+#             */
/*   Updated: 2023/11/28 15:26:11 by lgabet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_info(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->var->write_mut);
	printf("%lld %d %s\n", (get_actual_time() - philo->time_start), philo->number, str);
	pthread_mutex_unlock(&philo->var->write_mut);
}

void	eating_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	print_info(philo, "has taken a fork");
	if (philo->number != philo->var->number_of_philo - 1)
		pthread_mutex_lock(&philo->var->philo[philo->number + 1].right_fork);
	else
		pthread_mutex_lock(&philo->var->philo[0].right_fork);
	print_info(philo, "has taken a fork");
	print_info(philo, "is eating");
	usleep(philo->var->time_eat);
	pthread_mutex_unlock(&philo->right_fork);
	if (philo->number != philo->var->number_of_philo)
		pthread_mutex_unlock(&philo->var->philo[philo->number + 1].right_fork);
	else
		pthread_mutex_unlock(&philo->var->philo[0].right_fork);
	philo->number_of_meal++;
}

void	sleep_routine(t_philo *philo)
{
	print_info(philo, "is sleeping");
	usleep(philo->var->time_sleep);
}

void *routine_philo(void *arg)
{
    t_philo *philo = (t_philo *)arg;

	philo->time_start = get_actual_time();
	print_info(philo, "is thinking");
	while (are_all_alive(arg) && philo->number_of_meal != philo->var->total_eat)
	{
		eating_routine(philo);
		sleep_routine(philo);
		print_info(philo, "is thinking");
	}
	// printf("END OF A PHILO\n");
	philo->alive = false;
	return (0);
}